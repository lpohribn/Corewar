/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:54:01 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/04 14:54:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_clients(WINDOW *win, t_server *srv)
{
	int	cl;
	int	printed;

	cl = 0;
	printed = 0;
	while (cl < MAX_CLIENTS)
	{
		if (srv->client[cl].used && srv->client[cl].computer == false)
		{
			mvwprintw(win, 39 + printed, 198, "%d. %s", printed + 1,
			srv->client[cl].clientname);
			++printed;
		}
		++cl;
	}
}

void				print_connections(t_data *d)
{
	mvwprintw(d->vis.win, 37, 228, "--VIEWERS--");
	print_clients(d->vis.win, &d->srv);
	mvwprintw(d->vis.win, 58, 228, "--LOGS--");
	display_logs(d->vis.win, &d->srv, 60, 233);
}
