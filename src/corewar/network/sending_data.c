/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:00:15 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/03 18:00:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	client_gone(t_data *d, t_server *srv, t_client *cl)
{
	char const	*who;

	if (cl->isplayer)
	{
		who = "Player";
		if ((srv->srv_status & WSTAT_START) == 0)
		{
			--d->num_players;
			srv->available_id |= 0x1 << (cl->player_id - 1);
			shift_players(d, srv);
		}
	}
	else
	{
		who = "Viewer";
		--srv->num_viewers;
	}
	sprintf(srv->buff[srv->buff_i++], "%s %s(%s:%d) is gone", who,
	cl->clientname, cl->ip, cl->port);
	close(cl->sockfd);
	FD_CLR(cl->sockfd, &srv->net.master);
	ft_memset(cl, 0, sizeof(t_client));
}

inline static void	send_to_all(t_data *d, t_server *srv, t_token *t)
{
	int	i_fd;

	i_fd = 3;
	while (i_fd <= srv->net.fdmax)
	{
		if (FD_ISSET(i_fd, &srv->net.write_fds))
		{
			if (i_fd != srv->net.sockfd)
			{
				if (send_token(d, i_fd, t) == 0)
					client_gone(d, srv, get_client(srv->client, i_fd));
			}
		}
		++i_fd;
	}
}

int					sending_data(t_data *d, t_server *srv)
{
	t_token	t;

	ft_bzero(t.type, sizeof(t_token));
	if (srv->srv_status & WSTAT_END)
		ft_memcpy(t.type, "end", 3);
	else if (srv->srv_status & WSTAT_EXIT)
		ft_memcpy(t.type, "exit", 4);
	else if (srv->srv_status & WSTAT_START)
	{
		if (d->num_players == 0)
			ft_memcpy(t.type, "no player", 9);
		else
			ft_memcpy(t.type, "game", 4);
	}
	else
		ft_memcpy(t.type, "countdown", 9);
	ft_memcpy(t.data, d, sizeof(t_data));
	send_to_all(d, srv, &t);
	return (0);
}
