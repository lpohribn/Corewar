/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:02:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:02:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_handle_nan(t_data_printf *d, long double val)
{
	char		*str;
	const char	flag = d->chr > 91;

	d->prec = 0;
	if ((d->fl.sign || d->fl.plus) && val == val)
		d->width--;
	if (INFINITY == val)
		str = flag ? "inf" : "INF";
	else
		str = flag ? "nan" : "NAN";
	if (!d->fl.minus)
		ft_put_width(d, 3);
	if (d->fl.sign)
		d->buff[d->buff_i++] = '-';
	if (d->fl.plus && !d->fl.sign && val == val)
		d->buff[d->buff_i++] = '+';
	while (*str)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = *str++;
	}
	if (d->fl.minus)
		ft_put_width(d, 3);
}
