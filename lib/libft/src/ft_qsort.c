/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:46:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/30 18:46:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(int *arr, size_t len)
{
	size_t	b;
	size_t	e;
	int		piv;

	b = 0;
	e = len;
	piv = (arr[b] + arr[e]) / 2;
	while (b <= e)
	{
		while (arr[b] < piv)
			b++;
		while (arr[e] > piv)
			e--;
		if (b <= e)
		{
			ft_swap(&arr[b++], &arr[e]);
			if (e)
				e--;
		}
	}
	if (e)
		ft_qsort(arr, e);
	if (len > b)
		ft_qsort(arr + b, len - b);
}
