/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:48:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 15:48:12 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_star(t_data_printf *d, const char **pos, va_list *arg)
{
	int			value;
	const char	*ptr;

	value = 0;
	ptr = ++(*pos);
	while (*ptr >= '0' && *ptr <= '9')
	{
		value = value * 10 + (*ptr - '0');
		ptr++;
	}
	if (*ptr == '$')
	{
		(*pos) = ++ptr;
		if (value == 0)
			return (0);
		return (va_arg(*ft_count_arg(d, value), int));
	}
	else
		value = va_arg(*arg, int);
	return (value);
}
