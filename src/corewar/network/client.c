/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:43:02 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/03 15:43:04 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	key_event(t_data *d, t_network *net)
{
	int		key;

	key = getch();
	if (key == KEY_ESC)
	{
		shutdown(net->sockfd, SHUT_RDWR);
		close(net->sockfd);
		xexit(d, EXIT_SUCCESS);
	}
	else if (key == KEY_RESIZE)
		d->vis.win = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
}

inline static void	reinit(t_data *d, t_token *t, t_network *net)
{
	void	*win;
	_Bool	leaks;

	leaks = d->leaks;
	win = (void*)d->vis.win;
	ft_memcpy(d, t->data, sizeof(t_data));
	d->vis.win = (WINDOW*)win;
	d->beg_pc = NULL;
	d->server = false;
	d->leaks = leaks;
	ft_memcpy(&d->srv.net, net, sizeof(t_network));
}

inline static void	display_game(t_data *d, WINDOW *win)
{
	werase(win);
	print_window(win);
	print_title(win);
	print_memory(win, d->memory, d->vis.cell, false);
	print_pause(win, d->vis.pause);
	print_players(win, d->player, d->num_players);
	print_info_sidebar(d, win);
	if (!d->num_processes)
		print_winner(d);
	else
		print_hearts(d);
	mvwprintw(win, 11, 230, "--INFO--");
	mvwprintw(win, 24, 229, "--PLAYERS--");
	print_connections(d);
	mvwprintw(win, 69, 18, "--CONTROLS--");
	mvwprintw(win, 71, 30, "ESC - exit");
	wattroff(win, COLOR_PAIR(WHITE_BLACK));
	wrefresh(win);
}

inline static void	client_loop(t_data *d, t_network *net)
{
	t_token	t;

	while (1)
	{
		if (recv_token(d, net->sockfd, &t) == 0)
			xerror(d, NULL, 10);
		reinit(d, &t, net);
		if (ft_strcmp(t.type, "denied") == 0)
			xerror(d, (char*)t.data, 11);
		else if (ft_strcmp(t.type, "no player") == 0)
			xerror(d, NULL, 12);
		else if (ft_strcmp(t.type, "countdown") == 0)
			display_countdown(d, &d->srv);
		else if (ft_strcmp(t.type, "game") == 0)
			display_game(d, d->vis.win);
		else if (ft_strcmp(t.type, "end") == 0 ||
			ft_strcmp(t.type, "exit") == 0)
			break ;
		else
			xerror(d, t.type, 13);
		key_event(d, net);
	}
}

int					client(t_data *d, const char *argv[])
{
	t_network	net;

	if (create_client(d, &net, argv) < 0)
		return (-1);
	init_ncurses(d);
	client_loop(d, &net);
	shutdown(net.sockfd, SHUT_RDWR);
	close(net.sockfd);
	nodelay(stdscr, false);
	getch();
	xexit(d, EXIT_SUCCESS);
}
