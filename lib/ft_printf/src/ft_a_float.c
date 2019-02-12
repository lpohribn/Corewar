/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:48:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/12 12:48:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	int		ft_calc_expo_a(long double *val)
{
	size_t				i;
	int					ret;

	ret = 0;
	if (*val == INFINITY)
		return (0);
	while (*val >= 2l)
	{
		*val /= 2l;
		++ret;
	}
	i = 0;
	while (*val < 1l && ++i < 1000)
	{
		*val *= 2l;
		--ret;
	}
	while (*val >= 2l)
	{
		*val /= 2l;
		++ret;
	}
	return (i == 1000 ? 0 : ret);
}

inline	static	int		ft_count_len_a(long double val)
{
	size_t		res;
	long double	prev;

	res = 0;
	prev = val;
	val = (val - (intmax_t)val) * 16l;
	while (prev > val || val > prev)
	{
		++res;
		prev = val;
		val = (val - (intmax_t)val) * 16l;
	}
	return ((res) ? res - 1 : res);
}

inline	static	void	ft_put_expo_a(t_data_printf *d, int expo, int expo_len)
{
	int		i;

	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 3)
		ft_print_buff(d);
	d->buff[d->buff_i++] = (d->chr == 'A') ? 'P' : 'p';
	d->buff[d->buff_i++] = (expo >= 0) ? '+' : '-';
	if (expo < 0)
		expo = -expo;
	i = 0;
	d->buff_i += expo_len;
	while (i++ < expo_len)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i - i] = "0123456789"[expo % 10];
		expo /= 10;
	}
}

void					ft_a_float(t_data_printf *d, long double val)
{
	const int	expo = ft_calc_expo_a(&val);
	const int	expo_len = ft_count_dig(NULL, expo < 0 ? -expo : expo, 10);

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec == -1)
		d->prec = ft_count_len_a(val);
	if (d->prec > 0 || d->fl.sharp)
		d->width--;
	if (d->fl.plus || d->fl.sign || d->fl.space)
		d->width--;
	d->width -= 5;
	if (!d->fl.minus && !d->fl.zero)
		ft_put_width(d, expo_len);
	ft_put_sign(d, 0, 0);
	if (!d->fl.minus && d->fl.zero)
		ft_put_width(d, expo_len);
	ft_printf_dtoa(d, val + 0.5l * ft_powld(0.0625l, d->prec), 16l);
	ft_put_expo_a(d, expo, expo_len);
	if (d->fl.minus)
		ft_put_width(d, expo_len);
}
