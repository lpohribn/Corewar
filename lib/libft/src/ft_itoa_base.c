/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:31:59 by rnovodra          #+#    #+#             */
/*   Updated: 2018/01/09 12:47:08 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static size_t	ft_dig(int value, int base)
{
	size_t len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

inline static char		*ft_tranfer(int value, int base)
{
	size_t		size;
	char		*res;
	long int	min;

	size = ft_dig(value, base);
	min = value;
	if (!(value < 0 && base == 10 ?
		(res = (char*)malloc(sizeof(char) * ++size + 1)) :
		(res = (char*)malloc(sizeof(char) * size + 1))))
		return (NULL);
	res[size] = '\0';
	if (min < 0)
		min *= -1;
	while (size-- > 0)
	{
		res[size] = "0123456789ABCDEF"[min % base];
		min /= base;
	}
	if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}

char					*ft_itoa_base(int value, int base)
{
	char	*res;

	if (base < 2 || base > 16)
		return (NULL);
	if (!(res = ft_tranfer(value, base)))
		return (NULL);
	return (res);
}
