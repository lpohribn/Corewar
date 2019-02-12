/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expo_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:35:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:35:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_calc_expo(t_data_printf *d, long double *val)
{
	int		expo;
	int		check;

	expo = 0;
	if (*val == INFINITY)
		return (0);
	if (d->prec < 0)
		d->prec = 6;
	while (*val >= 10.0l)
	{
		*val /= 10.0l;
		++expo;
	}
	check = 0;
	while (*val < 1.0l && ++check < 1000)
	{
		*val *= 10.0l;
		--expo;
	}
	while ((*val += 0.5l * ft_powld(1.0l / 10.0l, d->prec)) >= 10.0l)
	{
		*val /= 10.0l;
		++expo;
	}
	return (check == 1000 ? 0 : expo);
}

inline	static	void	ft_put_expo(t_data_printf *d, int expo, int expo_len)
{
	int		i;

	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 3)
		ft_print_buff(d);
	d->buff[d->buff_i++] = (d->chr == 'E' || d->chr == 'G') ? 'E' : 'e';
	d->buff[d->buff_i++] = (expo >= 0) ? '+' : '-';
	if (expo < 0)
		expo = -expo;
	i = 0;
	if (expo < 10)
		d->buff[d->buff_i++] = '0';
	d->buff_i += expo_len;
	while (i++ < expo_len)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i - i] = "0123456789"[expo % 10];
		expo /= 10;
	}
}

void					ft_expo_form(t_data_printf *d, long double val)
{
	const int	expo = ft_calc_expo(d, &val);
	const int	expo_len = ft_count_dig(NULL, expo < 0 ? -expo : expo, 10);
	int			val_len;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	val_len = ft_count_double(val);
	if (d->prec > 0 || d->fl.sharp)
		d->width--;
	if (d->fl.plus || d->fl.sign || d->fl.space)
		d->width--;
	d->width -= 2 + (expo_len < 10 ? 2 : expo_len);
	if (!d->fl.minus && !d->fl.zero)
		ft_put_width(d, val_len);
	if (d->fl.plus || d->fl.space || d->fl.sign)
		ft_put_sign(d, 0, 0);
	if (!d->fl.minus && d->fl.zero)
		ft_put_width(d, val_len);
	ft_printf_dtoa(d, val, 10l);
	ft_put_expo(d, expo, expo_len);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
