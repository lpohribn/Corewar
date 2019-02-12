/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:29:34 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 17:29:35 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrjoin(const char **arr1, const char **arr2)
{
	char **new;

	if (!arr1 || !arr2)
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) *
		((size_t)ft_arrlen(arr1) + (size_t)ft_arrlen(arr1) + 1))))
		return (NULL);
	if (!(ft_arrcpy(new, arr1)))
	{
		ft_arrfree((void*)&new);
		return (NULL);
	}
	if (!(ft_arrcat(new, arr2)))
	{
		ft_arrfree((void*)&new);
		return (NULL);
	}
	return (new);
}
