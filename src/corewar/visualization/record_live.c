/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:08:10 by lpohribn          #+#    #+#             */
/*   Updated: 2019/01/09 12:08:11 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	record_live(t_data *d)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (d->vis.cell[i].live_times)
		{
			if (d->vis.cell[i].color >= 1 && d->vis.cell[i].color <= 5)
				d->vis.cell[i].color += 10;
			if (d->vis.pause == false)
				d->vis.cell[i].live_times--;
		}
		if (!d->vis.cell[i].live_times)
		{
			if (d->vis.cell[i].color >= 11 && d->vis.cell[i].color <= 16)
				d->vis.cell[i].color -= 10;
		}
		++i;
	}
}
