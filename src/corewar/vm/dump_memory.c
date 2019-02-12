/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:34:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 15:34:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_memory(t_data *d)
{
	unsigned char const	*memory = d->memory;
	unsigned int const	octets = d->octets;
	unsigned int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % octets == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x", memory[i++]);
		if (i % octets == 0 && i < MEM_SIZE)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
	xexit(d, EXIT_SUCCESS);
}
