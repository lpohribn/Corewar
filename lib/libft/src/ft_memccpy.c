/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:56:19 by rnovodra          #+#    #+#             */
/*   Updated: 2017/10/29 16:54:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;

	dst = (unsigned char*)dest;
	str = (unsigned char*)src;
	i = 0;
	while (n > i)
	{
		dst[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
