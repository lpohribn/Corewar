/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 18:05:04 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/03 18:05:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	int		ft_wchar_size(wchar_t ch)
{
	if (ch <= 127)
		return (1);
	else if (ch <= 2047)
		return (2);
	else if (ch <= 65535)
		return (3);
	else if (ch <= 1114111)
		return (4);
	else
		return (0);
}

inline	static	void	ft_putwchar(t_data_printf *d,
						int val_len, wchar_t value)
{
	if (FT_PRINTF_BUFF_SIZE <= (d->buff_i + val_len))
		ft_print_buff(d);
	if (val_len == 1 || MB_CUR_MAX == 1)
		d->buff[d->buff_i++] = (char)value;
	else if (val_len == 2)
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

inline static	int		ft_wstrlen(t_data_printf *d, wchar_t *str)
{
	int	char_len;
	int	str_len;

	char_len = 0;
	str_len = 0;
	while (*str && (str_len < d->prec || d->prec == -1))
	{
		char_len = ft_wchar_size(*str);
		if (char_len + str_len <= d->prec || d->prec == -1)
			str_len += char_len;
		else
			break ;
		str++;
	}
	return (str_len);
}

inline	static	void	ft_putwstr(t_data_printf *d, wchar_t *str, int str_len)
{
	wchar_t		*begin;
	int			char_len;
	int			printed_len;

	begin = str;
	printed_len = 0;
	while (*str && printed_len < str_len)
	{
		char_len = ft_wchar_size(*str);
		if ((printed_len += char_len) <= str_len)
			ft_putwchar(d, char_len, *str++);
	}
}

void					ft_wstring(t_data_printf *d, wchar_t *value)
{
	int		val_len;

	if (!value)
	{
		ft_string(d, NULL);
		return ;
	}
	else
		val_len = ft_wstrlen(d, value);
	if (d->prec >= 0 && d->prec < val_len)
		val_len = d->prec;
	d->prec = -1;
	if (d->fl.minus == 0)
		ft_put_width(d, val_len);
	ft_putwstr(d, value, val_len);
	if (d->fl.minus == 1)
		ft_put_width(d, val_len);
}
