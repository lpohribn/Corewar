/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_countdown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 14:29:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/30 14:29:45 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				display_logs(WINDOW *win, t_server *srv,
					const int y, const int x)
{
	int	i;

	i = 0;
	while (i < srv->buff_i)
	{
		mvwprintw(win, y + i, x - HALF(ft_strlen(srv->buff[i])),
		"%s", srv->buff[i]);
		++i;
	}
}

void				display_clients(WINDOW *win, t_client *cl)
{
	int	i;
	int	j;
	int	num;

	j = 2;
	num = 0;
	i = -1;
	while (++i < MAX_CLIENTS)
		if (cl[i].used == true)
		{
			if (cl[i].isplayer)
			{
				wattron(win, COLOR_PAIR(cl[i].player_id));
				mvwprintw(win, 7 + cl[i].player_id * 2,
				WIN_WCENTR - HALF(ft_strlen(cl[i].clientname) + 11),
				"Player %s(P%d) ", cl[i].clientname, cl[i].player_id);
				mvwprintw(win, 8 + cl[i].player_id * 2,
				WIN_WCENTR - HALF(ft_strlen(cl[i].champname) + 18),
				"His champion is \"%s\"", cl[i].champname);
				wattroff(win, COLOR_PAIR(cl[i].player_id));
			}
			else
				mvwprintw(win, j++, 2, "%d. %s", ++num, cl[i].clientname);
		}
}

inline static void	display_key_info(WINDOW *win, _Bool server)
{
	int	start;

	start = WIN_WIDTH - HALF(20);
	mvwprintw(win, 1, start - 34, "--CONTROL KEYS--");
	mvwprintw(win, 8, start - 42, "ESC - close the server");
	if (server)
	{
		mvwprintw(win, 9, start - 42, "ENTER - immediately start the game");
		mvwprintw(win, 10, start - 42, "SPACE - stop the timer");
	}
}

inline static void	display_main_window(WINDOW *win, const int msec,
					const int num_players, const int num_viewers)
{
	wattron(win, COLOR_PAIR(BLACK_GREY));
	mvwvline(win, 0, 80, 42, 26 + NUM_LOGS + 1);
	mvwvline(win, 0, 197, 42, 26 + NUM_LOGS + 1);
	mvwvline(win, 0, 0, 42, 22);
	mvwvline(win, 0, WIN_WIDTH - 1, 42, 22);
	mvwhline(win, 26 + NUM_LOGS, 80, 42, 118);
	mvwhline(win, 22, 0, 42, WIN_WIDTH);
	mvwhline(win, 0, 0, 42, WIN_WIDTH);
	wattroff(win, COLOR_PAIR(BLACK_GREY));
	mvwprintw(win, 2, WIN_WCENTR - HALF(14 + 2 + 1 + 3),
	"Game start at %2d:%.3d", (WAIT_TIME - msec) / MSEC_PER_SEC,
	(WAIT_TIME - msec) % MSEC_PER_SEC);
	mvwprintw(win, 3, WIN_WCENTR - HALF(9 + 2),
	"Players: %2d", num_players);
	mvwprintw(win, 4, WIN_WCENTR - HALF(9 + 2),
	"Viewers: %2d", num_viewers);
	mvwprintw(win, 23, WIN_WCENTR - 2, "--LOGS--");
	mvwprintw(win, 1, 32, "--VIEWERS--");
	mvwprintw(win, 6, WIN_WCENTR - 4, "Players:");
}

void				display_countdown(t_data *d, t_server *srv)
{
	WINDOW		*win;
	const char	*what;

	win = d->vis.win;
	if (d->server)
		what = "waiting for client on";
	else
		what = "connecting to server";
	werase(win);
	mvwprintw(win, 1, WIN_WCENTR - HALF(34 + 15 + 1 + 4),
	"Corewar is %s: %15s:%4d", what,
	inet_ntoa(srv->net.addr.sin_addr), ntohs(srv->net.addr.sin_port));
	display_main_window(win, srv->msec, d->num_players, srv->num_viewers);
	display_key_info(win, d->server);
	display_logs(win, srv, 25, WIN_WCENTR);
	display_clients(win, srv->client);
	wrefresh(win);
}
