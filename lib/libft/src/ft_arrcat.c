/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:40:54 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 17:40:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcat(char **dest, const char **src)
{
	size_t	i;
	ssize_t len;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if ((len = ft_arrlen(src)) < 0)
		return (NULL);
	while (src[i] != NULL)
	{
		if (!(dest[len + i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	if (dest[len + i] != NULL)
		dest[len + i] = NULL;
	return (dest);
}
