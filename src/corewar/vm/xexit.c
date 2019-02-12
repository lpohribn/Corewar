/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:31:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 15:31:57 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	clean_processs(t_data *d)
{
	t_process	*pc;

	pc = d->beg_pc;
	while (pc)
		delete_pc(d, &pc);
}

static inline void	clean_server(t_server *srv)
{
	int	i;

	i = 3;
	while (i < srv->net.fdmax)
	{
		shutdown(i, SHUT_RDWR);
		close(i);
		++i;
	}
}

void				xexit(t_data *d, const int status)
{
	if (d->vis.isinit && isendwin() == false)
		endwin();
	if (d->visual_mode)
		delwin(d->vis.win);
	if (d->num_processes)
		clean_processs(d);
	if (d->server)
	{
		d->srv.srv_status = WSTAT_EXIT;
		pthread_join(d->srv.pthread, NULL);
		clean_server(&d->srv);
	}
	if (d->leaks)
		system("leaks -q corewar");
	exit(status);
}
