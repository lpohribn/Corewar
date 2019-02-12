/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hearts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:35:38 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/04 14:35:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_heart(WINDOW *win, int x)
{
	mvwprintw(win, 69, x, "%S", L8);
	mvwprintw(win, 70, x, "%S", L9);
	mvwprintw(win, 71, x, "%S", L10);
	mvwprintw(win, 72, x, "%S", L11);
	mvwprintw(win, 73, x, "%S", L12);
}

void				print_hearts(t_data *d)
{
	int	i;
	int	start;

	i = 0;
	start = 155 - 20 * d->num_players / 2;
	while (i < d->num_players)
	{
		if (d->player[i].last_live == (unsigned int)d->cur_cycle)
			wattron(d->vis.win, A_BOLD);
		wattron(d->vis.win, COLOR_PAIR(i + 1));
		print_heart(d->vis.win, start + 20 * i);
		if (d->player[i].last_live == (unsigned int)d->cur_cycle)
			wattroff(d->vis.win, A_BOLD);
		wattroff(d->vis.win, COLOR_PAIR(i + 1));
		++i;
	}
}
