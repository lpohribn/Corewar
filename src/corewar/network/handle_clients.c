/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_clients.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:04:40 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/28 12:04:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	denied_accept(t_data *d, t_server *srv,
					t_client *cl, t_token *t)
{
	sprintf(srv->buff[srv->buff_i++],
	"Client(%s) %s(%s:%d) tried to connect. Denied.", t->type, cl->clientname,
	cl->ip, cl->port);
	ft_memcpy(t->type, "denied", 6);
	if (cl->isplayer)
	{
		if (srv->srv_status & WSTAT_START)
			ft_memcpy(t->data, "The game has begun", 18);
		else
			ft_memcpy(t->data, "too many players", 17);
	}
	else
		ft_memcpy(t->data, "too many viewers", 17);
	send_token(d, cl->sockfd, t);
	shutdown(cl->sockfd, SHUT_RDWR);
	close(cl->sockfd);
	FD_CLR(cl->sockfd, &srv->net.master);
	ft_memset(cl, 0, sizeof(t_client));
}

inline static void	load_player(t_data *d, t_server *srv,
					t_client *cl, t_token *t)
{
	short int	shift;
	char const	av_id = srv->available_id;

	shift = 0;
	while (shift < 4)
	{
		if ((av_id >> shift) & 0x1)
		{
			cl->player_id = (shift + 1);
			srv->available_id ^= (0x1 << shift);
			break ;
		}
		++shift;
	}
	ft_bzero(&d->player[shift], sizeof(t_player));
	ft_memcpy(&d->player[shift], (t->data + NAME + 1), sizeof(t_player));
	ft_memcpy(cl->champname, d->player[shift].prog_name, PROG_NAME_LENGTH);
	d->player[shift].id = (shift + 1);
}

inline static int	who_is_client(t_data *d, t_server *srv,
					t_client *cl, t_token *t)
{
	ft_memcpy(cl->clientname, t->data, NAME);
	if (ft_strcmp(t->type, "player") == 0)
		cl->isplayer = true;
	if ((srv->num_viewers == MAX_VIEWERS && cl->isplayer == false) ||
		(d->num_players == MAX_PLAYERS && cl->isplayer) ||
		(srv->srv_status & WSTAT_START && cl->isplayer))
	{
		denied_accept(d, srv, cl, t);
		return (-1);
	}
	if (cl->isplayer)
	{
		++d->num_players;
		load_player(d, srv, cl, t);
	}
	else
		++srv->num_viewers;
	sprintf(srv->buff[srv->buff_i++], "New %s %s(%s:%d)", t->type,
	cl->clientname, cl->ip, cl->port);
	return (0);
}

inline static void	connection_accept(t_data *d, t_server *srv)
{
	t_client	*cl;
	socklen_t	addrlen;
	t_token		t;

	if (srv->buff_i >= NUM_LOGS)
		srv->buff_i = 0;
	cl = get_client(srv->client, -1);
	addrlen = sizeof(struct sockaddr_in);
	if ((cl->sockfd = accept(srv->net.sockfd,
	(struct sockaddr *)&cl->addr, &addrlen)) < 0)
		xerror(d, NULL, 1);
	else
	{
		cl->used = true;
		ft_strcpy(cl->ip, inet_ntoa(cl->addr.sin_addr));
		cl->port = ntohs(cl->addr.sin_port);
		if (recv_token(d, cl->sockfd, &t) == 0)
			return ;
		if (who_is_client(d, srv, cl, &t) < 0)
			return ;
		FD_SET(cl->sockfd, &srv->net.master);
		if (cl->sockfd > srv->net.fdmax)
			srv->net.fdmax = cl->sockfd;
	}
}

void				*handle_clients(void *data)
{
	t_data *const	d = (t_data*)data;
	t_server *const	srv = &d->srv;
	struct timeval	timeout;
	int				i_fd;

	timeout.tv_sec = 0;
	timeout.tv_usec = 500;
	while ((srv->srv_status & WSTAT_EXIT) == 0)
	{
		srv->net.read_fds = srv->net.master;
		srv->net.write_fds = srv->net.master;
		if (select(srv->net.fdmax + 1, &srv->net.read_fds,
			&srv->net.write_fds, NULL, &timeout) < 0)
			xerror(d, NULL, 1);
		i_fd = 3;
		while (i_fd <= srv->net.fdmax)
		{
			if (FD_ISSET(i_fd, &srv->net.read_fds))
				if (i_fd == srv->net.sockfd)
					connection_accept(d, srv);
			++i_fd;
		}
		sending_data(d, srv);
	}
	pthread_exit((void*)"success");
}
