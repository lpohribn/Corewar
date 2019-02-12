/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:26:19 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/17 19:22:53 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_cpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sorc;

	dest = (char*)dst;
	sorc = (char*)src;
	while (n--)
		*dest++ = *sorc++;
}

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	uintmax_t	*dest;
	uintmax_t	*source;
	size_t		xlen;

	if (!dst && !src)
		return (NULL);
	dest = (uintmax_t*)dst;
	source = (uintmax_t*)src;
	xlen = n / 8;
	while (1)
	{
		if (!xlen)
		{
			ft_cpy((void*)dest, (void*)source, n % 8);
			return (dst);
		}
		*dest++ = *source++;
		xlen--;
	}
	return (dst);
}
