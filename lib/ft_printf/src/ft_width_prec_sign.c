/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:56:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 11:56:29 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_put_width(t_data_printf *d, int val_len)
{
	char	c;
	int		width;
	int		prec;

	if (!d->fl.flt)
		prec = d->prec - val_len;
	else
		prec = d->prec;
	c = ' ';
	width = d->width;
	if (d->fl.zero && (d->prec < 0 || d->fl.flt) && !d->fl.minus)
		c = '0';
	if (prec < 0 || val_len == 0)
		prec = 0;
	width -= (val_len + prec);
	while (width-- > 0)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
	d->width = width;
}

void		ft_put_prec(t_data_printf *d, uintmax_t val, int len, int base)
{
	register int		prec;

	prec = d->prec - len;
	if (d->fl.sharp == 1 && base == 8 && val != 0)
		--prec;
	while (prec-- > 0)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '0';
	}
}

void		ft_put_sign(t_data_printf *d, uintmax_t val, int base)
{
	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 3)
		ft_print_buff(d);
	if (d->fl.plus && !d->fl.sign)
		d->buff[d->buff_i++] = '+';
	else if (d->fl.sign && base != 16 && base != 8)
		d->buff[d->buff_i++] = '-';
	else if (d->fl.space && !d->fl.sign && !d->fl.plus)
		d->buff[d->buff_i++] = ' ';
	if ((d->fl.sharp && (base == 8 || base == 16) &&
		val) || d->chr == 'p' || d->chr == 'a' || d->chr == 'A')
	{
		d->buff[d->buff_i++] = '0';
		if ((base == 16 && d->chr == 'x') || d->chr == 'p' ||
			d->chr == 'a')
			d->buff[d->buff_i++] = 'x';
		else if (base != 8)
			d->buff[d->buff_i++] = 'X';
	}
}
