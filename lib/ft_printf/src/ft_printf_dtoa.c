/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:33:41 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/04 13:33:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_pre_point(t_data_printf *d, long double *val,
						long double base)
{
	long double		dec_part;
	int				val_len;
	char			*str;

	str = (d->chr == 'A') ? "0123456789ABCDEF" : "0123456789abcdef";
	dec_part = 1l;
	val_len = 1;
	while (*val / dec_part >= base)
	{
		++val_len;
		dec_part *= base;
	}
	while (val_len--)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		(d->buff[d->buff_i++] = str[(unsigned char)(*val / dec_part)]);
		*val -= (uintmax_t)(*val / dec_part) * dec_part;
		dec_part /= base;
	}
}

inline	static	void	ft_aft_point(t_data_printf *d, long double val,
						long double base)
{
	int		prec;
	char	*str;

	str = (d->chr == 'A') ? "0123456789ABCDEF" : "0123456789abcdef";
	prec = d->prec;
	val = (val - (uintmax_t)(val)) * base;
	while (prec > 0)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = str[(unsigned char)(val)];
		val = (val - (uintmax_t)val) * base;
		--prec;
	}
}

void					ft_printf_dtoa(t_data_printf *d, long double val,
						long double base)
{
	ft_pre_point(d, &val, base);
	if (d->prec > 0 || d->fl.sharp == 1)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '.';
		if (d->prec > 0)
			ft_aft_point(d, val, base);
	}
}
