/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:39:43 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/12 14:03:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (n > i + j && str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == find[j] && find[j] != '\0' && n > i + j)
			j++;
		if (find[j] == '\0')
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
