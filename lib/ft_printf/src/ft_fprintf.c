/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:24:18 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/13 17:24:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_fprintf(const char *file, const char *restrict format, ...)
{
	va_list		arg;
	int			done;
	int			fd;

	if (!format || file)
		return (-1);
	if ((fd = open(file, O_CREAT | O_RDWR, 0666)) < 0)
		return (-1);
	va_start(arg, format);
	done = ft_vdprintf(fd, format, &arg);
	va_end(arg);
	if (close(fd) < 0)
		return (-1);
	return (done);
}
