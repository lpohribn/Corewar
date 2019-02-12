/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:11:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/31 14:11:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	init_colors(void)
{
	start_color();
	init_color(COLOR_BLUE, 408, 408, 408);
	init_color(COLOR_MAGENTA, 650, 0, 950);
	init_color(COLOR_YELLOW, 1000, 500, 113);
	init_pair(RED_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(VIOL_BLACK, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
	init_pair(GREY_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(BLACK_VIOL, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);
	init_pair(GREY_GREY, COLOR_BLUE, COLOR_BLUE);
	init_pair(WHITE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(WHITE_VIOL, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);
	init_pair(WHITE_GREY, COLOR_WHITE, COLOR_BLUE);
	init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLACK_ORANGE, COLOR_BLACK, COLOR_YELLOW);
	init_pair(ORANGE_BLACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(BLACK_GREY, COLOR_BLACK, COLOR_BLUE);
}

void				init_ncurses(t_data *d)
{
	setlocale(LC_ALL, "");
	initscr();
	if (!(d->vis.win = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0)))
		xerror(d, "", -1);
	d->vis.isinit = true;
	keypad(stdscr, true);
	cbreak();
	noecho();
	timeout(0);
	curs_set(false);
	init_colors();
	scrollok(d->vis.win, false);
}
