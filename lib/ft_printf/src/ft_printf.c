/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:15:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 12:15:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *restrict format, ...)
{
	va_list		arg;
	int			done;

	if (!format)
		return (-1);
	va_start(arg, format);
	done = ft_vdprintf(1, format, &arg);
	va_end(arg);
	return (done);
}
