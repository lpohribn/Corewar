/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:23:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/15 16:25:18 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(const int fd, const char *restrict format, va_list *arg)
{
	t_data_printf	d;
	const char		*pos = format;

	if (!format)
		return (-1);
	d.buff_i = 0;
	d.ret = 0;
	d.fd = fd;
	va_copy(d.begin, *arg);
	while (d.ret != -1 && *pos)
	{
		if (FT_PRINTF_BUFF_SIZE <= d.buff_i)
			ft_print_buff(&d);
		if (*pos == '%')
			pos = ft_spec(&d, pos, arg);
		else if (*pos == '{')
			pos = ft_color(&d, pos);
		else
			d.buff[d.buff_i++] = *pos++;
	}
	if (d.buff_i != 0)
		ft_print_buff(&d);
	return (d.ret);
}
