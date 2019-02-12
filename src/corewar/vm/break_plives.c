/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_plives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:03:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/21 16:03:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	break_plives(t_data *d)
{
	t_player *const	pl = d->player;
	short int		i;

	i = 0;
	while (i < d->num_players)
	{
		pl[i].curr_period_live = 0;
		++i;
	}
}
