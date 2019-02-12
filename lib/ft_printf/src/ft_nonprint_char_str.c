/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonprint_char_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:33:31 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/11 14:33:32 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	int		ft_nonprint_strlen(unsigned char *str)
{
	int		val_len;

	val_len = 0;
	while (*str != 0)
	{
		if (*str > 127)
		{
			val_len += 2;
		}
		else
			++val_len;
		str++;
	}
	return (val_len * 2);
}

inline	static	void	ft_put_nonprint(t_data_printf *d, int val_len,
						unsigned char value)
{
	if (FT_PRINTF_BUFF_SIZE <= (d->buff_i + val_len))
		ft_print_buff(d);
	else if (val_len == 2)
	{
		d->buff[d->buff_i++] = '^';
		d->buff[d->buff_i++] = value + 64;
	}
	else if (val_len == 4)
	{
		d->buff[d->buff_i++] = 'M';
		d->buff[d->buff_i++] = '-';
		d->buff[d->buff_i++] = '^';
		d->buff[d->buff_i++] = value - 64;
	}
	else
		d->buff[d->buff_i++] = value;
}

inline	static	void	ft_write_str(t_data_printf *d, unsigned char *value,
						int val_len)
{
	unsigned char	*begin;
	int				np_len;
	int				printed_len;

	begin = value;
	printed_len = 0;
	while (*value && printed_len < val_len)
	{
		if (*value < 32 && *value != 9 && *value != 10)
			np_len = 2;
		else if (*value > 126 && *value < 160)
			np_len = 4;
		else
			np_len = 1;
		if ((printed_len += np_len) <= val_len)
			ft_put_nonprint(d, np_len, *value++);
	}
}

void					ft_nonprint_str(t_data_printf *d, unsigned char *value)
{
	int				val_len;

	if (!value)
	{
		ft_string(d, NULL);
		return ;
	}
	else
		val_len = ft_nonprint_strlen(value);
	if (d->prec >= 0 && d->prec < val_len)
		val_len = d->prec;
	d->prec = -1;
	if (d->fl.minus == 0)
		ft_put_width(d, val_len);
	ft_write_str(d, value, val_len);
	if (d->fl.minus == 1)
		ft_put_width(d, val_len);
}

void					ft_nonprint_char(t_data_printf *d, unsigned char value)
{
	int			val_len;

	val_len = 1;
	if (value < 32 && value != 9 && value != 10)
		val_len = 2;
	else if (value > 126 && value < 160)
		val_len = 4;
	if (d->prec == 0 || d->prec > val_len)
		d->prec = -1;
	if (!d->fl.minus)
		ft_put_width(d, val_len);
	ft_put_nonprint(d, val_len, value);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
