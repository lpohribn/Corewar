/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:04:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/29 19:04:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_pc(t_data *d, t_process const *cpy, unsigned int const pos)
{
	static unsigned int	id = 1;
	t_process			*ret;

	ret = (t_process*)ft_memalloc(sizeof(t_process));
	if (!ret)
		xerror(d, NULL, 1);
	if (cpy)
		ft_memcpy(ret, cpy, sizeof(t_process));
	ret->run_cycles = -1;
	ret->pos = pos;
	ret->id = id++;
	ret->next = NULL;
	ret->prev = NULL;
	if (d->beg_pc)
	{
		d->beg_pc->prev = ret;
		ret->next = d->beg_pc;
	}
	d->beg_pc = ret;
	++d->num_processes;
}
