/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:42:02 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 16:42:03 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **dest, const char **arr)
{
	size_t i;

	if (!dest || !arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if (!(dest[i] = ft_strdup(arr[i])))
			return (NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
