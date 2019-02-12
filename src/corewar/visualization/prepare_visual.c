/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:21:21 by lpohribn          #+#    #+#             */
/*   Updated: 2019/01/09 13:21:23 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	cut_player_name(t_data *d)
{
	char	*name;
	int		i;

	i = 0;
	while (i < d->num_players)
	{
		name = d->player[i].prog_name;
		if (ft_strlen(name) > NAME_SIZE)
		{
			name[NAME_SIZE - 1] = '.';
			name[NAME_SIZE] = '\0';
		}
		++i;
	}
}

inline static void	record_memory(t_data *d)
{
	int	j;
	int	i;
	int	place;
	int	num_player;

	num_player = 0;
	place = MEM_SIZE / d->num_players;
	while (num_player < d->num_players)
	{
		i = place * num_player;
		j = 0;
		while (j < (int)d->player[num_player].bot_size)
		{
			d->vis.cell[i].color = num_player + 1;
			++i;
			++j;
		}
		++num_player;
		while (i <= MEM_SIZE - 1)
		{
			d->vis.cell[i].color = GREY_BLACK;
			++i;
		}
	}
}

void				prepare_visual(t_data *d)
{
	if (d->vis.isinit == false)
		init_ncurses(d);
	d->dump = false;
	d->info = false;
	d->vis.pause = true;
	d->vis.one_step = false;
	d->vis.select_pc = d->beg_pc;
	d->vis.speed = DEFAULT_SPEED;
	cut_player_name(d);
	record_memory(d);
	while (visualization(d))
		;
}
