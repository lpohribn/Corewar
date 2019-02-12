/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:36:52 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:36:54 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fork_op(t_data *d, t_process *const pc)
{
	short int	new_pos;
	short int	real_pos;

	new_pos = (short)get_arg(d, PC_POS(1), 2);
	if (pc->opcode == 12)
		real_pos = new_pos % IDX_MOD;
	else
		real_pos = new_pos;
	create_pc(d, pc, PC_POS(real_pos));
	if (d->info & 4)
		ft_printf("P %4u | %s %d (%hd)\n", pc->id,
		g_op_tab[pc->opcode].name, new_pos, pc->pos + real_pos);
	pc->pos = PC_POS(1 + 2);
}
