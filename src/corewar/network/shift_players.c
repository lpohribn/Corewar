/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:38:06 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/03 15:38:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void		change_player_id(t_client *cl,
						const int was_id, const int now_id)
{
	int	i;

	i = 0;
	while (i < MAX_CLIENTS)
	{
		if (cl[i].used && cl[i].isplayer && cl[i].player_id == was_id)
			cl[i].player_id = now_id;
		++i;
	}
}

void					shift_players(t_data *d, t_server *srv)
{
	int	free_id;
	int	busy_id;

	free_id = 0;
	while (free_id < d->num_players)
	{
		if ((srv->available_id >> free_id) & 0x1)
		{
			busy_id = free_id;
			while (++busy_id < d->num_players)
			{
				if (((srv->available_id >> busy_id) & 0x1) == 0)
					break ;
			}
			srv->available_id |= 0x1 << busy_id;
			srv->available_id ^= 0x1 << free_id;
			change_player_id(srv->client, busy_id + 1, free_id + 1);
			ft_memcpy(&d->player[free_id], &d->player[busy_id],
				sizeof(t_player));
			d->player[free_id].id = free_id + 1;
			free_id = 0;
		}
		else
			++free_id;
	}
}
