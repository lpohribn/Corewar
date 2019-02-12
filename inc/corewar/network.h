/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:51:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/19 19:51:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_H
# define NETWORK_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <sys/time.h>

# define MSEC_PER_SEC	1000
# define WAIT_TIME		30 * MSEC_PER_SEC
# define PORT			8080
# define MAX_CLIENTS	16
# define MAX_VIEWERS	MAX_CLIENTS - MAX_PLAYERS
# define NUM_LOGS		14

# define IP				17
# define NAME			20
# define TYPE			15
# define BSIZE			80
# define DATA			65536

# define HALF(x)		(x) / 2

# define WSTAT_START	0x1
# define WSTAT_EXIT		0x2
# define WSTAT_PAUSE	0x4
# define WSTAT_END		0x8

typedef struct s_data	t_data;

typedef struct	s_client
{
	_Bool				used;
	_Bool				isplayer;
	_Bool				computer;
	int					port;
	int					sockfd;
	struct sockaddr_in	addr;
	char				ip[IP];
	char				player_id;
	char				clientname[NAME + 1];
	char				champname[PROG_NAME_LENGTH + 1];
}				t_client;

typedef struct	s_token
{
	char			type[TYPE + 1];
	unsigned char	data[DATA];
}				t_token;

typedef struct	s_network
{
	struct sockaddr_in	addr;
	int					sockfd;
	int					fdmax;
	fd_set				master;
	fd_set				read_fds;
	fd_set				write_fds;
}				t_network;

typedef struct	s_server
{
	pthread_t		pthread;
	t_network		net;
	char			*ip;
	char			available_id;
	char			srv_status;
	_Bool			chat_stat;
	int				num_viewers;
	int				msec;
	int				buff_i;
	char			buff[NUM_LOGS + 1][BSIZE + 1];
	t_client		client[MAX_CLIENTS + 1];
}				t_server;

/*
**	server functions
*/

int				server(t_data *d);
int				create_server(t_data *d);
int				sending_data(t_data *d, t_server *srv);
void			shift_players(t_data *d, t_server *srv);

/*
**	client functions
*/

int				client(t_data *d, const char *argv[]);
int				create_client(t_data *d, t_network *net, const char *argv[]);

/*
** display functions
*/

void			display_countdown(t_data *d, t_server *srv);
void			display_clients(WINDOW *win, t_client *cl);
void			display_logs(WINDOW *win, t_server *srv,
				const int y, const int x);

/*
** utilities functions
*/

int				connect_request(int *sockfd, struct sockaddr_in *my_addr,
				const char *ip);
bool			is_valid_ip(const char *ip);
int				recv_token(t_data *d, const int sockfd, t_token *t);
int				send_token(t_data *d, const int sockfd, t_token *t);
t_client		*get_client(t_client *c, int sockfd);

/*
** thread function
*/

void			*handle_clients(void *data);

#endif
