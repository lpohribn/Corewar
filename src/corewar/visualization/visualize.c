/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:34:09 by lpohribn          #+#    #+#             */
/*   Updated: 2018/10/31 15:34:11 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	visualization(t_data *d)
{
	clock_t	begin;
	clock_t	delta;

	begin = clock();
	werase(d->vis.win);
	if (d->num_processes == 0)
		d->vis.pause = true;
	record_live(d);
	record_pc(d);
	print_game(d);
	key_events(d);
	wrefresh(d->vis.win);
	delta = (clock() - begin) / 1000;
	if (1000 / d->vis.speed > (int)delta)
		usleep((1000 / d->vis.speed - delta) * 1000);
	if (d->vis.one_step == true)
	{
		d->vis.one_step = false;
		d->vis.pause = true;
		return (false);
	}
	return (d->vis.pause);
}
