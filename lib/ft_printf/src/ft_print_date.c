/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:10:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/11 17:10:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_date(t_data_printf *d)
{
	const time_t	timer = time(NULL);
	char			*str;

	str = ctime(&timer);
	str[24] = '\0';
	ft_string(d, str);
}
