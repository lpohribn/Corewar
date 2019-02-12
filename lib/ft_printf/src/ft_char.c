/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:25:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/30 16:25:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_putwchar(t_data_printf *d,
						int val_len, wchar_t value)
{
	if (val_len == 2)
	{
		d->buff[d->buff_i++] = ((value & 0xFC0) >> 6) | (0xC080 >> 8);
		d->buff[d->buff_i++] = ((value & 0x3F) | (0xC080));
	}
	else if (val_len == 3)
	{
		d->buff[d->buff_i++] = ((value & 0x3F000) >> 12) | (0xE08080 >> 16);
		d->buff[d->buff_i++] = ((value & 0xFC0) >> 6) | (0xE08080 >> 8);
		d->buff[d->buff_i++] = ((value & 0x3F) | (0xE08080));
	}
	else
	{
		d->buff[d->buff_i++] = (value >> 18) | (0xF0808080 >> 24);
		d->buff[d->buff_i++] = ((value & 0x3F000) >> 12) | (0xF0808080 >> 16);
		d->buff[d->buff_i++] = ((value & 0xFC0) >> 6) | (0xF0808080 >> 8);
		d->buff[d->buff_i++] = ((value & 0x3F) | (0xF0808080));
	}
}

void					ft_char(t_data_printf *d, wchar_t value)
{
	int			val_len;

	val_len = 0;
	if (value <= 127 || d->fl.size != 3 || MB_CUR_MAX == 1)
		val_len = 1;
	else if (value <= 2047)
		val_len = 2;
	else if (value <= 65535)
		val_len = 3;
	else if (value <= 1114111)
		val_len = 4;
	if (d->prec == 0 || d->prec > val_len)
		d->prec = -1;
	if (!d->fl.minus)
		ft_put_width(d, val_len);
	if (FT_PRINTF_BUFF_SIZE <= (d->buff_i + val_len))
		ft_print_buff(d);
	if (val_len == 1)
		d->buff[d->buff_i++] = (char)value;
	else
		ft_putwchar(d, val_len, value);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
