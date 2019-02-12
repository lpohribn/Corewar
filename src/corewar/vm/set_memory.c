/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:02:10 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/12 16:02:11 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_memory(t_process *const pc, t_data *d, int pos, int const value)
{
	unsigned int	i;
	unsigned char	*ptr;
	const char		int_size = 4;

	ptr = (unsigned char*)&value;
	i = 0;
	while (i < int_size)
	{
		d->memory[pos] = ptr[int_size - i - 1];
		if (d->visual_mode)
		{
			d->vis.cell[pos].fl_light = 50;
			d->vis.cell[pos].color = pc->which_player;
		}
		pos = (pos + 1) % MEM_SIZE;
		++i;
	}
}
