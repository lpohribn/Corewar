/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:06:16 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 19:06:17 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	champ_comment(t_player *const player,
					const unsigned char *ptr)
{
	int		tmp;

	tmp = *(int*)ptr;
	ft_bytesrev(&tmp, sizeof(int));
	player->bot_size = tmp;
	if (tmp > CHAMP_MAX_SIZE)
		return (9);
	ptr += 4;
	ft_memcpy(player->comment, ptr, COMMENT_LENGTH + 1);
	ptr += COMMENT_LENGTH + 4;
	if (*(int*)(ptr - 4) != 0)
		return (7);
	return (0);
}

static inline int	get_program_part(t_player *const player, const int fd)
{
	unsigned char	buff[PROG_SIZE];
	unsigned char	*ptr;
	int				ret;
	int				tmp;

	if ((ret = read(fd, buff, PROG_SIZE)) < 0)
		return (1);
	if (ret < PROG_SIZE)
		return (4);
	ptr = buff;
	tmp = *(int*)ptr;
	ft_bytesrev(&tmp, sizeof(int));
	if (tmp != COREWAR_EXEC_MAGIC)
		return (5);
	ptr += 4;
	ft_memcpy(player->prog_name, ptr, PROG_NAME_LENGTH + 1);
	ptr += PROG_NAME_LENGTH + 4;
	if (*(int*)(ptr - 4) != 0)
		return (6);
	ret = champ_comment(player, ptr);
	return (ret);
}

static inline int	get_exec_code(const int fd, t_player *const player)
{
	const int		bot_size = player->bot_size;
	unsigned char	*exec_code;
	int				ret;

	exec_code = player->exec_code;
	if ((ret = read(fd, exec_code, bot_size + 1)) < 0)
		return (1);
	if (ret != bot_size)
		return (8);
	return (0);
}

static inline void	set_player_id(t_data *d, t_player *const player)
{
	static int	num = 1;
	int			i;

	i = -1;
	while (++i < d->num_players)
	{
		if (num == d->player[i].id)
			++num;
		if (d->num != 0)
		{
			if (d->num == d->player[i].id)
				d->num = 0;
		}
	}
	if (d->num == 0)
		player->id = num++;
	else
	{
		player->id = d->num;
		d->num = 0;
	}
}

int					handle_champion(t_data *d, const char *champname)
{
	t_player		*player;
	int				fd;
	int				error;

	player = &d->player[d->num_players];
	if ((fd = open(champname, O_RDONLY)) < 0)
		xerror(d, champname, 2);
	error = get_program_part(player, fd);
	if (error == 0)
		error = get_exec_code(fd, player);
	if (close(fd) < 0)
		xerror(d, NULL, 1);
	if (error != 0)
		xerror(d, champname, error);
	set_player_id(d, player);
	player->last_live = -1;
	return (0);
}
