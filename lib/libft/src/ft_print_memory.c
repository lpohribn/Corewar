/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:49:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/01/21 16:49:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void	ft_putascii(unsigned char c)
{
	if (c > 31 && c < 127)
		ft_putchar(c);
	else
		ft_putchar('.');
}

inline static void	ft_puthex(unsigned char c)
{
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

inline static void	ft_print_line(unsigned char *str,
					size_t start, size_t size)
{
	size_t		i;

	i = start;
	while (i < start + 16 && i < size)
	{
		ft_puthex(str[i]);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	while (i < start + 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = start;
	while (i < start + 16 && i < size)
	{
		ft_putascii(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void				ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t			c;

	c = 0;
	str = (unsigned char*)addr;
	while (c < size)
	{
		ft_print_line(str, c, size);
		c += 16;
	}
}
