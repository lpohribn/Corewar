/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_dimensional_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:12:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/12 10:12:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_put_index(t_data_printf *d, int i)
{
	const int	index_len = ft_count_dig(NULL, i, 10);
	int			space;

	space = 4;
	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 5 + index_len + space)
		ft_print_buff(d);
	d->buff[d->buff_i++] = '[';
	ft_printf_itoa(d, i, 10, index_len);
	d->buff[d->buff_i++] = ']';
	d->buff[d->buff_i++] = '-';
	d->buff[d->buff_i++] = '-';
	d->buff[d->buff_i++] = '>';
	while (space-- > index_len)
		d->buff[d->buff_i++] = ' ';
}

inline	static	void	ft_chartype_array(t_data_printf *d, char **array)
{
	const int	width = d->width;
	const int	prec = d->prec;
	int			i;

	i = 0;
	while (array[i] != NULL)
	{
		if (d->fl.sharp)
			ft_put_index(d, i);
		d->width = width;
		d->prec = prec;
		ft_string(d, array[i]);
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '\n';
		i++;
	}
	if (i == 0)
	{
		if (d->fl.sharp)
			ft_put_index(d, i);
		ft_string(d, NULL);
		(d->buff[d->buff_i++] = '\n');
	}
}

inline	static	void	ft_wchartype_array(t_data_printf *d, wchar_t **array)
{
	const int	width = d->width;
	const int	prec = d->prec;
	int			i;

	i = 0;
	while (array[i] != NULL)
	{
		if (d->fl.sharp)
			ft_put_index(d, i);
		d->width = width;
		d->prec = prec;
		ft_wstring(d, array[i]);
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '\n';
		i++;
	}
	if (i == 0)
	{
		if (d->fl.sharp)
			ft_put_index(d, i);
		ft_string(d, NULL);
		(d->buff[d->buff_i++] = '\n');
	}
}

void					ft_two_dimensional_array(t_data_printf *d, va_list *arg)
{
	void	*check;

	check = (void*)va_arg(*arg, uintmax_t);
	if (!check)
	{
		ft_string(d, NULL);
		return ;
	}
	if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
		ft_print_buff(d);
	if (d->fl.size == 3 || d->chr == 'M')
		ft_wchartype_array(d, (wchar_t**)check);
	else
		ft_chartype_array(d, (char**)check);
}
