/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:21:19 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/21 16:21:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static int	key_event(WINDOW *win, t_server *srv)
{
	int	key;

	key = getch();
	if (key == KEY_ESC)
	{
		srv->srv_status = WSTAT_EXIT;
		return (1);
	}
	else if (key == KEY_RETURN)
	{
		srv->srv_status = WSTAT_START;
		return (1);
	}
	else if (key == KEY_SPACE)
		srv->srv_status ^= WSTAT_PAUSE;
	else if (key == KEY_RESIZE)
		wresize(win, WIN_HEIGHT, WIN_WIDTH);
	return (0);
}

inline static int	countdown_game(t_data *d, t_server *srv)
{
	clock_t		start;
	clock_t		dtime;
	clock_t		pause;

	start = clock();
	pause = 0;
	while (WAIT_TIME > srv->msec)
	{
		if (srv->srv_status & (WSTAT_EXIT | WSTAT_START))
			break ;
		if (!(srv->srv_status & WSTAT_PAUSE))
		{
			dtime = clock() - start;
			srv->msec = dtime * MSEC_PER_SEC / CLOCKS_PER_SEC;
		}
		else
		{
			pause = clock() - start - dtime;
			start += pause;
		}
		key_event(d->vis.win, srv);
		display_countdown(d, srv);
	}
	srv->srv_status |= WSTAT_START;
	return (0);
}

/*
** server create thread, which all the time will work with clients
** until end of program
*/

int					server(t_data *d)
{
	d->visual_mode = true;
	init_ncurses(d);
	create_server(d);
	if (pthread_create(&d->srv.pthread, NULL, handle_clients, d) < 0)
		xerror(d, NULL, 1);
	countdown_game(d, &d->srv);
	if (d->srv.srv_status & WSTAT_EXIT)
		xexit(d, EXIT_SUCCESS);
	if (d->num_players == 0)
		xerror(d, NULL, 12);
	erase();
	return (0);
}
