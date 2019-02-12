/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:23:21 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/29 12:23:23 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_players(WINDOW *win, t_player *p, const int num_player)
{
	int i;
	int	x;
	int	y;

	i = 0;
	y = 25;
	while (i < num_player)
	{
		if (i > 1)
			y = 29;
		x = 198 + i % 2 * 37;
		wattron(win, COLOR_PAIR(i + 1));
		mvwprintw(win, y + 1, x, "P%d: %s", i + 1, p[i].prog_name);
		wattron(win, COLOR_PAIR(WHITE_BLACK));
		if ((int)p[i].last_live == -1)
			mvwprintw(win, y + 2, x, "Last live: %19d", 0);
		else
			mvwprintw(win, y + 2, x, "Last live: %19d", p[i].last_live);
		mvwprintw(win, y + 3, x,
		"Lives in current period: %5d", p[i].curr_period_live);
		wattroff(win, COLOR_PAIR(WHITE_BLACK));
		wattroff(win, COLOR_PAIR(i + 1));
		i++;
	}
}

void	print_pause(WINDOW *win, _Bool pause)
{
	if (pause)
	{
		wattron(win, COLOR_PAIR(3));
		mvwprintw(win, 13, 198, "PAUSE: %18s", "ON");
		wattroff(win, COLOR_PAIR(3));
	}
	else
	{
		wattron(win, COLOR_PAIR(1));
		mvwprintw(win, 13, 198, "PAUSE: %18s", "OFF");
		wattroff(win, COLOR_PAIR(1));
	}
}

void	print_info_sidebar(t_data *d, WINDOW *win)
{
	mvwprintw(win, 15, 198, "Processes: %14d", d->num_processes);
	mvwprintw(win, 17, 198, "Cycles/second limit: %4d", d->vis.speed);
	mvwprintw(win, 19, 198, "Cycle: %18d", d->cur_cycle);
	mvwprintw(win, 13, 244, "Cycle_to_die: %4d", d->cycle_to_die);
	mvwprintw(win, 15, 244, "Cycle_DELTA: %5d", CYCLE_DELTA);
	mvwprintw(win, 17, 244, "NBR_LIVE: %8d", NBR_LIVE);
	mvwprintw(win, 19, 244, "MAX_CHECKS: %6d", MAX_CHECKS);
}
