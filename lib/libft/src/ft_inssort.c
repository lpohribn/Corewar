/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inssort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 20:04:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/30 20:04:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inssort(int *arr, size_t len)
{
	size_t	pass;
	size_t	i;

	pass = 0;
	while (pass < len - 1)
	{
		i = pass + 1;
		while (i < len)
		{
			if (arr[pass] > arr[i])
				ft_swap(&arr[i], &arr[pass]);
			++i;
		}
		++pass;
	}
}
