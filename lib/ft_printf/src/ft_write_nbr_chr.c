/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:48:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/04 12:48:25 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_chr(t_data_printf *d, va_list *arg)
{
	intmax_t		*dest;

	if (d->fl.size == 0)
		dest = (intmax_t*)va_arg(*arg, int*);
	else if (d->fl.size == 1)
		dest = (intmax_t*)va_arg(*arg, int*);
	else if (d->fl.size == 2)
		dest = (intmax_t*)va_arg(*arg, int*);
	else if (d->fl.size == 3)
		dest = (intmax_t*)va_arg(*arg, long int*);
	else if (d->fl.size == 4)
		dest = (intmax_t*)va_arg(*arg, long long int*);
	else if (d->fl.size == 5)
		dest = (intmax_t*)va_arg(*arg, intmax_t*);
	else if (d->fl.size == 6)
		dest = (intmax_t*)va_arg(*arg, ptrdiff_t*);
	else
		dest = (intmax_t*)va_arg(*arg, ssize_t*);
	if (!dest)
		return ;
	*dest = d->buff_i + d->ret;
}
