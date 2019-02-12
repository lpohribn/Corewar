/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:13 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:38:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	show_live(t_data *d, t_player *const pl, const int pos)
{
	d->vis.cell[pos].live_times = 50;
	pl->last_live = d->cur_cycle;
	++pl->curr_period_live;
}

void				live_op(t_data *d, t_process *const pc)
{
	t_player *const	pl = d->player;
	int				name_player;
	int				i;

	++d->execution_live;
	name_player = get_arg(d, PC_POS(1), 4);
	if (d->info & 4)
		ft_printf("P %4u | live %d\n", pc->id, name_player);
	i = -1;
	while (++i < d->num_players)
	{
		if (pl[i].id == name_player * -1)
		{
			if (d->info & 1)
				ft_printf("A process shows that player %d (%s) is alive\n",
				pl[i].id, pl[i].prog_name);
			if (d->visual_mode)
				show_live(d, &pl[i], pc->pos);
			d->winner_id = i;
			break ;
		}
	}
	pc->live = 1;
	pc->live_cycle = d->cur_cycle;
	pc->pos = PC_POS(5);
}
