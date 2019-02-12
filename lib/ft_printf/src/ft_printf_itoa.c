/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:34:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 18:34:32 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_itoa(t_data_printf *d, uintmax_t value,
				int base, int len)
{
	char	*str;
	int		tmp;

	str = (d->chr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + len)
		ft_print_buff(d);
	tmp = d->buff_i + len;
	while (len--)
	{
		d->buff[d->buff_i + len] = str[value % base];
		value /= base;
	}
	d->buff_i = tmp;
}

void			ft_printf_apo_itoa(t_data_printf *d, uintmax_t value,
				int base, int len)
{
	int		dig;
	int		tmp;

	dig = 1;
	tmp = d->buff_i + len;
	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + len)
		ft_print_buff(d);
	while (len--)
	{
		if (dig % 4 == 0)
		{
			d->buff[d->buff_i + len] = ',';
			dig = 1;
		}
		else
		{
			d->buff[d->buff_i + len] = value % base + '0';
			value /= base;
			dig++;
		}
	}
	d->buff_i = tmp;
}
