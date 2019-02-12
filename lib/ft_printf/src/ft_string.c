/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:25:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/30 16:25:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_cpylast(t_data_printf *d, char *val, int len)
{
	int		i;
	char	*dst;

	dst = &d->buff[d->buff_i];
	i = 0;
	while (i < len && *val)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		(*dst++ = *val++);
		i++;
	}
	d->buff_i += i;
}

inline	static	void	ft_printf_strncpy(t_data_printf *d, char *val, int len)
{
	uintmax_t	*longword_val;
	uintmax_t	*longword_dst;
	int			i;

	i = 0;
	longword_dst = (uintmax_t *)&d->buff[d->buff_i];
	longword_val = (uintmax_t *)val;
	while (42)
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 8)
		{
			ft_print_buff(d);
			longword_dst = (uintmax_t *)d->buff;
		}
		if (i + 8 > len)
		{
			ft_cpylast(d, (char*)longword_val, len - i);
			break ;
		}
		*longword_dst++ = *longword_val++;
		d->buff_i += 8;
		i += 8;
	}
}

void					ft_string(t_data_printf *d, char *value)
{
	int		val_len;

	if (!value)
	{
		value = "(null)";
		val_len = 6;
	}
	else
		val_len = ft_strlen(value);
	if (d->prec >= 0 && d->prec < val_len)
		val_len = d->prec;
	d->prec = -1;
	if (d->fl.minus == 0)
		ft_put_width(d, val_len);
	if (val_len < FT_PRINTF_BUFF_SIZE - d->buff_i)
	{
		ft_memcpy(&d->buff[d->buff_i], value, val_len);
		d->buff_i += val_len;
	}
	else
		ft_printf_strncpy(d, value, val_len);
	if (d->fl.minus == 1)
		ft_put_width(d, val_len);
}
