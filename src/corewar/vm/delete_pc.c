/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:04:19 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/29 19:04:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		delete_pc(t_data *d, t_process **del)
{
	t_process *const todel = *del;
	t_process *const r = todel->next;
	t_process *const l = todel->prev;

	if (d->info & 8)
	{
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		todel->id, d->cur_cycle - todel->live_cycle, d->cycle_to_die);
	}
	free(todel);
	if (l)
		l->next = r;
	if (r)
		r->prev = l;
	if (todel == d->beg_pc)
		d->beg_pc = r;
	if (d->visual_mode && todel == d->vis.select_pc)
	{
		if (r)
			d->vis.select_pc = r;
		else
			d->vis.select_pc = l;
	}
	*del = r;
	--d->num_processes;
}
