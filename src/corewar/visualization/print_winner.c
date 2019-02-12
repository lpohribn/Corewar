/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:57:48 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/29 11:57:50 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_skull(WINDOW *win, int x)
{
	mvwprintw(win, 69, x, "%S", S1);
	mvwprintw(win, 70, x, "%S", S2);
	mvwprintw(win, 71, x, "%S", S3);
	mvwprintw(win, 72, x, "%S", S4);
	mvwprintw(win, 73, x, "%S", S5);
}

static inline void	print_cup(WINDOW *win, int x)
{
	mvwprintw(win, 69, x, "%S", C1);
	mvwprintw(win, 70, x, "%S", C2);
	mvwprintw(win, 71, x, "%S", C3);
	mvwprintw(win, 72, x, "%S", C4);
	mvwprintw(win, 73, x, "%S", C6);
}

void				print_winner(t_data *d)
{
	int	i;
	int	start;

	i = 0;
	start = 155 - 20 * d->num_players / 2;
	while (i < d->num_players)
	{
		wattron(d->vis.win, COLOR_PAIR(i + 1));
		if (i != d->winner_id)
			print_skull(d->vis.win, start + 20 * i);
		else
			print_cup(d->vis.win, start + 20 * i);
		wattroff(d->vis.win, COLOR_PAIR(i + 1));
		++i;
	}
	if (d->server)
		d->srv.srv_status |= WSTAT_END;
}
