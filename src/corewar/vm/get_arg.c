/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:19:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/05 17:19:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_arg(t_data *d, unsigned int pos, unsigned int const size)
{
	unsigned int	arg;
	unsigned char	*ptr;
	unsigned int	i;

	arg = 0;
	ptr = (unsigned char*)&arg;
	i = 0;
	while (i < size)
	{
		ptr[size - i - 1] = d->memory[pos];
		pos = (pos + 1) % MEM_SIZE;
		++i;
	}
	return (arg);
}
