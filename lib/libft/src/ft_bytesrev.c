/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytesrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 20:44:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/23 20:44:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bytesrev(void *a, size_t size)
{
	size_t			i;
	unsigned char	tmp;
	unsigned char	*byte;

	if (!a)
		return ;
	i = 0;
	byte = (unsigned char*)a;
	while (i < size - i)
	{
		tmp = byte[i];
		byte[i] = byte[size - 1 - i];
		byte[size - 1 - i] = tmp;
		i++;
	}
}
