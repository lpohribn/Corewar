/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:22:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/20 14:22:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		connect_request(int *sockfd, struct sockaddr_in *addr,
		const char *ip)
{
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (-1);
	addr->sin_family = AF_INET;
	addr->sin_port = htons(PORT);
	if ((addr->sin_addr.s_addr = inet_addr(ip)) == 0)
		return (-1);
	ft_memset(addr->sin_zero, '\0', sizeof(addr->sin_zero));
	return (0);
}
