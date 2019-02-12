/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:10:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/20 14:10:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

bool	is_valid_ip(const char *ip)
{
	struct sockaddr_in	sockaddr;
	int					isvalid;

	isvalid = inet_pton(AF_INET, ip, &(sockaddr.sin_addr));
	return (isvalid > 0);
}
