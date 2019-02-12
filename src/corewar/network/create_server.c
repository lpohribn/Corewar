/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:47:50 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/19 19:47:51 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline char		*get_host_ip(void)
{
	struct hostent	*host_entry;
	char			hostbuffer[256];
	int				hostname;

	if ((hostname = gethostname(hostbuffer, sizeof(hostbuffer)) < 0))
		return (NULL);
	if (!(host_entry = gethostbyname(hostbuffer)))
		return (NULL);
	return (inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0])));
}

static inline int		prepare_server(t_server *srv, t_network *net)
{
	int	set;

	set = true;
	if (setsockopt(net->sockfd, SOL_SOCKET,
	SO_REUSEADDR, &set, sizeof(int)) < 0)
		return (-1);
	if (setsockopt(net->sockfd, SOL_SOCKET,
		SO_NOSIGPIPE, &set, sizeof(int)) < 0)
		return (-1);
	if (bind(net->sockfd, (struct sockaddr*)&net->addr,
	sizeof(struct sockaddr)) < 0)
		return (-1);
	if (listen(net->sockfd, 10) < 0)
		return (-1);
	FD_ZERO(&net->master);
	FD_ZERO(&net->read_fds);
	net->fdmax = net->sockfd;
	FD_SET(net->sockfd, &net->master);
	srv->available_id = 0xf;
	return (0);
}

static inline void		set_busy_id(t_player *p, t_server *srv,
						const int num_players)
{
	int i;

	i = 0;
	while (i < num_players)
	{
		p[i].id = i + 1;
		srv->available_id ^= (0x1 << i);
		srv->client[i].used = true;
		srv->client[i].isplayer = true;
		srv->client[i].computer = true;
		srv->client[i].player_id = i + 1;
		ft_memcpy(srv->client[i].clientname, "COMPUTER ", 9);
		srv->client[i].clientname[9] = (i + 1) + '0';
		ft_memcpy(srv->client[i].champname,
		p[i].prog_name, PROG_NAME_LENGTH);
		++i;
	}
}

int						create_server(t_data *d)
{
	t_server	*srv;

	srv = &d->srv;
	if (!(srv->ip = get_host_ip()))
		xerror(d, NULL, 1);
	if (connect_request(&srv->net.sockfd, &srv->net.addr, srv->ip) < 0)
		xerror(d, NULL, 1);
	if (prepare_server(srv, &srv->net) < 0)
		xerror(d, NULL, 1);
	if (d->num_players)
		set_busy_id(d->player, srv, d->num_players);
	return (0);
}
