/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:13 by lpohribn          #+#    #+#             */
/*   Updated: 2018/11/28 16:24:15 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_controls(WINDOW *win)
{
	mvwprintw(win, 71, 30, "SPEED : 1X : + | -   DEFAULT SPEED: tab");
	mvwprintw(win, 72, 30,
	"       10X : Shift + plus | Shift + minus");
	mvwprintw(win, 73, 30, "ONE STEP/ONE CYCLE : enter");
	mvwprintw(win, 72, 5, "EXIT   : esc");
	mvwprintw(win, 71, 5, "PAUSE  : space");
	mvwprintw(win, 73, 5, "CHOOSE PROCESS : ⇧ | ⇩");
}

void	print_window(WINDOW *win)
{
	wattron(win, COLOR_PAIR(BLACK_GREY));
	wborder(win, 42, 42, 42, 42, 42, 42, 42, 42);
	mvwhline(win, 22, 196, 42, 196);
	mvwhline(win, 67, 0, 42, 196);
	mvwhline(win, 9, 196, 42, 196);
	mvwhline(win, 35, 196, 42, 196);
	mvwhline(win, 56, 196, 42, 196);
	mvwvline(win, 0, 196, 42, 196);
	wattroff(win, COLOR_PAIR(BLACK_GREY));
}
