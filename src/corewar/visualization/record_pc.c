/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:37:40 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/10 18:37:42 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	record_pc1(t_data *d)
{
	t_process	*pc;

	pc = d->beg_pc;
	while (pc)
	{
		d->vis.cell[pc->pos].process = 1;
		if (d->vis.cell[pc->pos].color <= 5)
			d->vis.cell[pc->pos].color += 5;
		if (pc == d->vis.select_pc && !d->server)
		{
			d->vis.prev_color = d->vis.cell[pc->pos].color - 5;
			d->vis.cell[pc->pos].color = BLACK_ORANGE;
		}
		pc = pc->next;
	}
}

void				record_pc(t_data *d)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (d->vis.cell[i].process)
		{
			if (d->vis.cell[i].color >= 6 && d->vis.cell[i].color <= 10)
				d->vis.cell[i].color -= 5;
			else if (d->vis.cell[i].color == BLACK_ORANGE && !d->server)
				d->vis.cell[i].color = d->vis.prev_color;
		}
		d->vis.cell[i].process = false;
		++i;
	}
	record_pc1(d);
}
