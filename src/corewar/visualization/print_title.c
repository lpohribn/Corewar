/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_title.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:45:44 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/19 19:45:47 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_title(WINDOW *win)
{
	wattron(win, COLOR_PAIR(ORANGE_BLACK));
	mvwprintw(win, 2, 201, "%S", L1);
	mvwprintw(win, 3, 201, "%S", L2);
	mvwprintw(win, 4, 201, "%S", L3);
	mvwprintw(win, 5, 201, "%S", L4);
	mvwprintw(win, 6, 201, "%S", L5);
	mvwprintw(win, 7, 201, "%S", L6);
	mvwprintw(win, 8, 205, "%S", L7);
	wattroff(win, COLOR_PAIR(ORANGE_BLACK));
}
