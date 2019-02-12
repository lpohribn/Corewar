/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:11:01 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 15:11:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_flags(t_data_printf *d)
{
	d->fl.sign = 0;
	d->fl.zero = 0;
	d->fl.minus = 0;
	d->fl.plus = 0;
	d->fl.space = 0;
	d->fl.sharp = 0;
	d->fl.long_db = 0;
	d->fl.apostr = 0;
	d->fl.size = 0;
	d->width = 0;
	d->prec = -1;
	d->data_arg = 0;
	d->fl.flt = 0;
}
