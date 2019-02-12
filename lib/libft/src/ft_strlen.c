/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:37:57 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/05 14:57:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *str)
{
	const char				*p;
	const unsigned long int	*lp;

	p = str;
	lp = (const unsigned long int*)p;
	while (42)
	{
		if ((*lp - 0x101010101010101L) & 0x8080808080808080L)
		{
			p = (const char *)(lp);
			TESTBYTE(0);
			TESTBYTE(1);
			TESTBYTE(2);
			TESTBYTE(3);
			TESTBYTE(4);
			TESTBYTE(5);
			TESTBYTE(6);
			TESTBYTE(7);
			TESTBYTE(8);
		}
		lp++;
	}
	return (0);
}
