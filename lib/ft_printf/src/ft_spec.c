/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:20:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 14:20:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	const	char	*ft_mng_flags(t_data_printf *d, const char *pos)
{
	while (*pos && (*pos == ' ' ||
		*pos == '0' || *pos == '-' ||
		*pos == '#' || *pos == '+' ||
		*pos == '\''))
	{
		if (!d->fl.space && !d->fl.plus && *pos == ' ')
			d->fl.space = 1;
		else if (!d->fl.zero && !d->fl.minus && *pos == '0')
			d->fl.zero = 1;
		else if (!d->fl.sharp && *pos == '#')
			d->fl.sharp = 1;
		else if (!d->fl.minus && *pos == '-')
			d->fl.minus = 1;
		else if (!d->fl.plus && *pos == '+')
			d->fl.plus = 1;
		else if (!d->fl.apostr && *pos == '\'')
			d->fl.apostr = 1;
		pos++;
	}
	return (pos);
}

inline	static	const	char	*ft_mng_dig(t_data_printf *d, const char *pos)
{
	int		digit;

	digit = 0;
	while (*pos >= '0' && *pos <= '9')
	{
		digit = digit * 10 + (*pos - '0');
		pos++;
	}
	if (*pos == '$')
	{
		pos++;
		d->data_arg = digit;
	}
	else
		d->width = digit;
	if (d->width < 0)
		d->ret = -1;
	return (pos);
}

inline	static	const	char	*ft_mng_prec(t_data_printf *d,
								const char *pos, va_list *arg)
{
	int		prec;

	prec = 0;
	pos++;
	if (*pos == '*')
		prec = ft_star(d, &pos, arg);
	else
		while (*pos >= '0' && *pos <= '9')
		{
			prec = prec * 10 + (*pos - '0');
			pos++;
		}
	if (prec < 0)
		prec = -1;
	d->prec = prec;
	return (pos);
}

inline	static	const	char	*ft_mng_size(t_data_printf *d, const char *pos)
{
	while (*pos && (*pos == 'h' || *pos == 'l' || *pos == 't' ||
		*pos == 'j' || *pos == 'z' || *pos == 'L'))
	{
		if (d->fl.size == 2 && *pos == 'h')
			d->fl.size = 1;
		else if (d->fl.size < 2 && *pos == 'h')
			d->fl.size = 2;
		else if (d->fl.size < 4 && d->fl.size == 3 && *pos == 'l')
			d->fl.size = 4;
		else if (d->fl.size < 5 && *pos == 'l')
			d->fl.size = 3;
		else if (d->fl.size < 6 && *pos == 'j')
			d->fl.size = 6;
		else if (d->fl.size < 7 && *pos == 't')
			d->fl.size = 7;
		else if (d->fl.size < 8 && *pos == 'z')
			d->fl.size = 8;
		else if (!d->fl.long_db && *pos == 'L')
			d->fl.long_db = 1;
		pos++;
	}
	return (pos);
}

const	char					*ft_spec(t_data_printf *d,
								const char *pos, va_list *arg)
{
	pos++;
	ft_set_flags(d);
	while (*pos)
	{
		if (*pos == ' ' || *pos == '0' ||
			*pos == '-' || *pos == '#' ||
			*pos == '+' || *pos == '\'')
			pos = ft_mng_flags(d, pos);
		else if (*pos >= '1' && *pos <= '9')
			pos = ft_mng_dig(d, pos);
		else if (*pos == '.')
			pos = ft_mng_prec(d, pos, arg);
		else if (*pos == 'h' || *pos == 'l' ||
			*pos == 'z' || *pos == 'j' ||
			*pos == 'L' || *pos == 't')
			pos = ft_mng_size(d, pos);
		else if (*pos == '*')
			d->width = ft_star(d, &pos, arg);
		else
		{
			ft_conv(d, *pos++, arg);
			break ;
		}
	}
	return (pos);
}
