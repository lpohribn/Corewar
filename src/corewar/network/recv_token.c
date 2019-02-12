/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:35:06 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/27 14:35:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		recv_token(t_data *d, const int sockfd, t_token *t)
{
	int	nbytes;

	ft_bzero(t, sizeof(t_token));
	while ((nbytes = recv(sockfd, t, sizeof(t_token), MSG_WAITALL)) <= 0)
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
