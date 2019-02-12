/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xerror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:22:59 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 18:23:00 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	other_errors(t_data *d, const char *msg, const int status)
{
	if (status == 7)
		ft_dprintf(STDERR_FILENO, "corewar: File %s: "
		"bot comment aren't terminated by a four null bytes\n", msg);
	else if (status == 8)
		ft_dprintf(STDERR_FILENO, "corewar: File %s: has a code size "
		"that differ from what its header says\n", msg);
	else if (status == 9)
		ft_dprintf(STDERR_FILENO, "corewar: File %s: "
		"has too large a code (%d bytes > %d bytes)\n",
		msg, d->player[d->num_players].bot_size, CHAMP_MAX_SIZE);
	else if (status == 10)
		ft_dprintf(STDERR_FILENO, "corewar: lost connection to the server\n",
		msg, d->player[d->num_players].bot_size, CHAMP_MAX_SIZE);
	else if (status == 11)
		ft_dprintf(STDERR_FILENO, "corewar: client accept denied. %s.\n", msg);
	else if (status == 12)
		ft_dprintf(STDERR_FILENO, "corewar: no player connected.\n");
	else if (status == 13)
		ft_dprintf(STDERR_FILENO, "corewar: ivalid type of token %s\n", msg);
	else
		ft_dprintf(STDERR_FILENO, "corewar: undefined error\n");
}

void				xerror(t_data *d, const char *msg, const int status)
{
	if (d->vis.isinit)
		endwin();
	if (status == -1)
		ft_dprintf(STDERR_FILENO, "corewar: error ncurses\n");
	else if (status == 1)
		ft_dprintf(STDERR_FILENO, "corewar: %s\n", strerror(errno));
	else if (status == 2)
		ft_dprintf(STDERR_FILENO, "corewar: %s: %s\n", msg, strerror(errno));
	else if (status == 3)
		ft_dprintf(STDERR_FILENO, "corewar: Too many champions, "
		"maximum of champions - %d\n", MAX_PLAYERS);
	else if (status == 4)
		ft_dprintf(STDERR_FILENO, "corewar: File %s is to small "
		"to be a champion\n", msg);
	else if (status == 5)
		ft_dprintf(STDERR_FILENO, "corewar: File %s has an invalid "
		"magic header\n", msg);
	else if (status == 6)
		ft_dprintf(STDERR_FILENO, "corewar: File %s: "
		"bot name aren't terminated by a four null bytes\n", msg);
	else
		other_errors(d, msg, status);
	xexit(d, status);
}
