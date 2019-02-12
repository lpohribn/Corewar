/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:50:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/30 19:50:31 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	create_processes(t_data *d, const int place)
{
	short int	i;

	i = 0;
	while (i < d->num_players)
	{
		create_pc(d, NULL, i * place);
		d->beg_pc->reg[0] = 0 - d->player[i].id;
		d->beg_pc->which_player = ++i;
	}
}

static inline void	load_players(t_data *d, const int place)
{
	short int		i;
	const t_player	*pl;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < d->num_players)
	{
		pl = &d->player[i];
		ft_memcpy(d->memory + place * i, pl->exec_code, pl->bot_size);
		ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n",
		pl->id, pl->bot_size, pl->prog_name, pl->comment);
		++i;
	}
}

static inline int	check_player_id(t_data *d)
{
	t_player const	*player = d->player;
	int				i;

	i = 0;
	while (i < d->num_players)
	{
		if (d->p_flag == false && player[i].id > MAX_PLAYERS)
		{
			ft_dprintf(STDERR_FILENO, "corewar: Invalid number"
			" of player [1 - %d]\n", MAX_PLAYERS);
			return (-1);
		}
		++i;
	}
	return (0);
}

int					prepare_game(t_data *d)
{
	int	place;

	if (d->num_players == 0)
	{
		ft_dprintf(STDERR_FILENO, "corewar: champions are missed\n");
		return (-1);
	}
	if (check_player_id(d) < 0)
		return (-1);
	place = MEM_SIZE / d->num_players;
	load_players(d, place);
	create_processes(d, place);
	if (d->visual_mode)
		prepare_visual(d);
	return (0);
}
