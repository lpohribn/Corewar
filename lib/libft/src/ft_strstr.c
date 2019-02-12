/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:07:30 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/15 16:29:54 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t i;
	size_t j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (find[j] != '\0' && str[i + j] != '\0' &&
				str[i + j] == find[j])
			j++;
		if (find[j] == '\0')
			return ((char*)&str[i]);
		i++;
	}
	if (str[i] == find[0])
		return ((char*)&str[i]);
	return (NULL);
}
