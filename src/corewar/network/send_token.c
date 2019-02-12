/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:35:01 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/27 14:35:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		send_token(t_data *d, const int sockfd, t_token *t)
{
	int	nbytes;

	while ((nbytes = send(sockfd, t, sizeof(t_token), 0)) <= 0)
	{
		if (nbytes == 0 || errno == EPIPE || errno == EINTR)
		{
			if (errno == EINTR)
			{
				errno = 0;
				continue ;
			}
			errno = 0;
			return (0);
		}
		else
			xerror(d, NULL, 1);
	}
	return (1);
}
