/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:03:50 by rnovodra          #+#    #+#             */
/*   Updated: 2017/10/26 16:05:18 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline intmax_t	ft_cpy(intmax_t dst, intmax_t cccc, size_t n)
{
	size_t		xlen;

	xlen = n / (64);
	while (xlen)
	{
		((intmax_t*)dst)[0] = cccc;
		((intmax_t*)dst)[1] = cccc;
		((intmax_t*)dst)[2] = cccc;
		((intmax_t*)dst)[3] = cccc;
		((intmax_t*)dst)[4] = cccc;
		((intmax_t*)dst)[5] = cccc;
		((intmax_t*)dst)[6] = cccc;
		((intmax_t*)dst)[7] = cccc;
		dst += 64;
		--xlen;
	}
	n %= 64;
	xlen = n / 8;
	while (xlen)
	{
		((intmax_t*)dst)[0] = cccc;
		dst += 8;
		--xlen;
	}
	return (dst);
}

void					*ft_memset(void *s, int c, size_t n)
{
	intmax_t	dst;
	intmax_t	cccc;

	dst = (intmax_t)s;
	if (n >= 8)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= (cccc << 16) << 16;
		dst = ft_cpy(dst, cccc, n);
	}
	n %= 8;
	while (n > 0)
	{
		((unsigned char*)dst)[0] = (unsigned char)c;
		dst++;
		--n;
	}
	return (s);
}
