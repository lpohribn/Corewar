/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:15:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 15:15:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	int		ft_count_prec(t_data_printf *d, long double val)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	val = (val - (uintmax_t)val) * 10.0l;
	while (i++ < d->prec)
	{
		if ((uintmax_t)val)
			len = i;
		val = (val - (uintmax_t)val) * 10.0l;
	}
	return (len);
}

inline	static	int		ft_count_prec_sharp(t_data_printf *d,
						long double val, int dec_len)
{
	int		len;
	int		i;
	int		flag;

	len = 0;
	i = dec_len;
	flag = 0;
	if ((uintmax_t)val)
		flag = 1;
	val = (val - (uintmax_t)val) * 10.0l;
	while (i < d->prec + dec_len)
	{
		if ((uintmax_t)val)
			flag = 1;
		if (flag == 1)
			i++;
		++len;
		val = (val - (uintmax_t)val) * 10.0l;
	}
	return (len);
}

inline	static	int		ft_check_prec(long double val)
{
	int		len;
	int		i;
	int		flag;

	len = 0;
	i = 0;
	flag = 0;
	if (!(uintmax_t)val)
	{
		val = (val - (uintmax_t)val) * 10.0l;
		len++;
	}
	while (!(uintmax_t)val && len < 6)
	{
		val = (val - (uintmax_t)val) * 10.0l;
		if ((uintmax_t)val)
			flag = 1;
		len++;
	}
	if (flag == 0)
		return (0);
	return (len);
}

inline	static	void	ft_prepare_f(t_data_printf *d, long double val)
{
	int			dec_len;
	long double	tmp;

	dec_len = ft_count_double(val);
	tmp = val + 0.5l * ft_powld(0.1l, d->prec + dec_len);
	if ((uintmax_t)val)
		d->prec -= dec_len;
	else
		dec_len = 0;
	if (!d->fl.sharp)
		d->prec = ft_count_prec(d, tmp);
	else
		d->prec = ft_count_prec_sharp(d, val, dec_len);
	if (d->prec == 0)
		d->prec = ft_check_prec(val);
	ft_float(d, val);
}

void					ft_g_float(t_data_printf *d, long double val)
{
	int				expo;
	long double		tmp;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec == -1)
		d->prec = 6;
	if (d->prec == 0)
		d->prec = 1;
	tmp = val;
	expo = ft_calc_expo(d, &tmp);
	if (expo < -4 || expo >= d->prec)
	{
		if ((uintmax_t)tmp)
			d->prec--;
		if (!d->fl.sharp)
			d->prec = ft_count_prec(d, tmp);
		ft_expo_form(d, val);
	}
	else
		ft_prepare_f(d, val);
}
