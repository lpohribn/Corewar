/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:18 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_client	*get_client(t_client *c, int sockfd)
{
	int	i;

	i = 0;
	while (i < MAX_CLIENTS + 1)
	{
		if (c[i].used == false && sockfd == -1)
			return (&c[i]);
		if (c[i].used && sockfd == c[i].sockfd)
			return (&c[i]);
		++i;
	}
	return (NULL);
}
