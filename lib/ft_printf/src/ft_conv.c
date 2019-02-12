/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:01:31 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 16:01:31 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_extra_conv(t_data_printf *d, char chr, va_list *arg)
{
	if (chr == 'a' || chr == 'A')
		ft_a_float(d, ft_get_float_val(d, arg));
	else if (chr == 'm' || chr == 'M')
		ft_two_dimensional_array(d, arg);
	else
		ft_char(d, chr);
}

inline	static	void	ft_conv_anoth(t_data_printf *d, char chr, va_list *arg)
{
	if (chr == 'x' || chr == 'X' || chr == 'p')
		ft_int(d, arg, 16);
	else if (chr == 'o' || chr == 'O')
		ft_int(d, arg, 8);
	else if (chr == 'n')
		ft_write_chr(d, arg);
	else if (chr == 'f' || chr == 'F')
		ft_float(d, ft_get_float_val(d, arg));
	else if (chr == 'e' || chr == 'E')
		ft_expo_form(d, ft_get_float_val(d, arg));
	else if (chr == 'g' || chr == 'G')
		ft_g_float(d, ft_get_float_val(d, arg));
	else if (chr == 'R')
		ft_nonprint_str(d, va_arg(*arg, unsigned char*));
	else if (chr == 'r')
		ft_nonprint_char(d, (unsigned char)va_arg(*arg, int));
	else if (chr == 'b')
		ft_int(d, arg, 2);
	else if (chr == 'k')
		ft_print_date(d);
	else
		ft_extra_conv(d, chr, arg);
}

void					ft_conv(t_data_printf *d, char chr, va_list *arg)
{
	if (d->width < 0)
	{
		d->width = -d->width;
		d->fl.minus = 1;
	}
	if (d->data_arg != 0)
		arg = ft_count_arg(d, d->data_arg);
	d->chr = chr;
	if (chr == 'D' || chr == 'U' ||
		chr == 'O' || chr == 'p' || chr == 'C')
		d->fl.size = 3;
	if (chr == 'd' || chr == 'i' || chr == 'u' ||
		chr == 'D' || chr == 'U')
		ft_int(d, arg, 10);
	else if (chr == 'c' || chr == 'C')
		ft_char(d, va_arg(*arg, int));
	else if (chr == 's' && d->fl.size != 3)
		ft_string(d, va_arg(*arg, char*));
	else if (chr == 'S' || chr == 's')
		ft_wstring(d, va_arg(*arg, wchar_t*));
	else
		ft_conv_anoth(d, chr, arg);
}
