/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:33:13 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/20 19:33:15 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_game(t_data *d)
{
	if (!d->num_processes)
		print_winner(d);
	else
		print_hearts(d);
	print_title(d->vis.win);
	print_window(d->vis.win);
	print_controls(d->vis.win);
	wattron(d->vis.win, COLOR_PAIR(WHITE_BLACK));
	print_pause(d->vis.win, d->vis.pause);
	print_players(d->vis.win, d->player, d->num_players);
	print_info_sidebar(d, d->vis.win);
	mvwprintw(d->vis.win, 11, 230, "--INFO--");
	mvwprintw(d->vis.win, 24, 229, "--PLAYERS--");
	mvwprintw(d->vis.win, 69, 32, "--CONTROLS--");
	if (d->server == false)
	{
		if (d->vis.select_pc)
			print_pc_list(d);
		mvwprintw(d->vis.win, 37, 228, "--PROCESSES--");
		mvwprintw(d->vis.win, 58, 228, "--REGISTER--");
	}
	else
		print_connections(d);
	wattroff(d->vis.win, COLOR_PAIR(WHITE_BLACK));
	print_memory(d->vis.win, d->memory, d->vis.cell, d->vis.pause);
}
