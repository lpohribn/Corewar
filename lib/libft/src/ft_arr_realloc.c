/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:51:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/16 14:51:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arr_realloc(const char **cpy, int size)
{
	char	**arr;

	if (!(arr = ft_arrnew(size, 0)))
		return (NULL);
	if (!cpy)
		return (arr);
	if (!(ft_arrcpy(arr, cpy)))
		return (NULL);
	return (arr);
}
