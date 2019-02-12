/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:31:37 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/20 19:31:39 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	key_event_speed(t_data *d, int key)
{
	if (key == KEY_MINUS && d->vis.speed > MIN_SPEED)
		--d->vis.speed;
	else if (key == KEY_PLUS && d->vis.speed < MAX_SPEED)
		d->vis.speed += 1;
	else if (key == KEY_SHIFT_MIN)
	{
		if (d->vis.speed <= 10)
			d->vis.speed = 1;
		else
			d->vis.speed -= 10;
	}
	else if (key == KEY_SHIFT_PL)
	{
		if (d->vis.speed < 990)
			d->vis.speed += 10;
		else
			d->vis.speed = MAX_SPEED;
	}
	else if (key == KEY_TAB)
		d->vis.speed = DEFAULT_SPEED;
}

void				key_events(t_data *d)
{
	int key;

	key = getch();
	if (key == KEY_SPACE)
		d->vis.pause = (d->vis.pause + 1) % 2;
	else if (key == KEY_ESC)
		xexit(d, EXIT_SUCCESS);
	else if (key == KEY_RESIZE)
		d->vis.win = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
	else if (key == KEY_DOWN && d->vis.select_pc && d->vis.select_pc->next)
	{
		if (d->vis.select_pos < NUM_PRINT_PC)
			++d->vis.select_pos;
		d->vis.select_pc = d->vis.select_pc->next;
	}
	else if (key == KEY_UP && d->vis.select_pc && d->vis.select_pc->prev)
	{
		if (d->vis.select_pos > 0)
			--d->vis.select_pos;
		d->vis.select_pc = d->vis.select_pc->prev;
	}
	else if (key == KEY_RETURN)
		d->vis.one_step = 1;
	else
		key_event_speed(d, key);
}
