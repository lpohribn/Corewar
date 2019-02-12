/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:52:10 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 15:52:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list			*ft_count_arg(t_data_printf *d, int arg)
{
	va_copy(d->param_arg, d->begin);
	while (--arg)
		va_arg(d->param_arg, long int);
	return (&d->param_arg);
}
