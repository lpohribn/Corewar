/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:31:49 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/17 19:25:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	ssize_t res;

	if (!dest || !src)
		return (-1);
	if ((size_t)ft_strlen(dest) > size)
		return (ft_strlen((char*)src) + size);
	res = ft_strlen(dest) + ft_strlen(src);
	while (*dest && size)
	{
		dest++;
		size--;
	}
	while (size > 1 && *src)
	{
		*(dest++) = *(src++);
		size--;
	}
	*dest = '\0';
	return (res);
}
