/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:56:00 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 16:56:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t n_ptr, size_t size)
{
	char	**arr;
	size_t	i;

	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (n_ptr + 1))))
		return (NULL);
	i = 0;
	while (i < n_ptr && size != 0)
	{
		if (!(arr[i] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		{
			ft_arrnfree((void***)&arr, i);
			return (NULL);
		}
		++i;
	}
	arr[i] = NULL;
	return (arr);
}
