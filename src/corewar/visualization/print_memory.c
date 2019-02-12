/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:31 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/05 15:25:33 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	color_on_off(WINDOW *win, t_cell *cell, _Bool status, int i)
{
	if (status == true)
	{
		if (cell[i].fl_light)
			wattron(win, COLOR_PAIR(cell[i].color) | A_BOLD);
		wattron(win, COLOR_PAIR(cell[i].color));
	}
	else
	{
		if (cell[i].fl_light)
			wattroff(win, A_BOLD);
		wattroff(win, COLOR_PAIR(cell[i].color));
	}
}

void				print_memory(WINDOW *win, unsigned char *memory,
					t_cell *cell, _Bool pause)
{
	int	y;
	int	x;
	int	i;

	y = 2;
	i = 0;
	while (y < HEIGHT)
	{
		x = 3;
		while (x < WIDTH && i < MEM_SIZE)
		{
			color_on_off(win, cell, true, i);
			mvwprintw(win, y, x, "%.2x", memory[i]);
			color_on_off(win, cell, false, i);
			if (cell[i].fl_light)
				if (pause == false)
					cell[i].fl_light--;
			x += 3;
			++i;
		}
		y++;
	}
}
