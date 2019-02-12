/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:04:25 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/14 15:04:26 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_bits(const void *addr, size_t size)
{
	int		i;
	char	c;
	char	*l;
	char	octet;

	l = (char*)addr;
	while (size--)
	{
		i = 7;
		octet = l[size];
		while (i >= 0)
		{
			c = (octet & (1 << i)) ? '1' : '0';
			ft_putchar(c);
			if (i % 4 == 0 && i)
				ft_putchar(' ');
			--i;
		}
		if (size)
			ft_putchar(' ');
	}
}
