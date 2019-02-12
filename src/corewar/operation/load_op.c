/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:38:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				load_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		reg;
	short int		offset;
	int				val;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		val = get_arg_val(d, pc, arg[0], &offset);
		if (arg[0] == T_IND && pc->opcode == 13)
			val >>= 16;
		reg = get_reg(d, pc, &offset);
		if (reg != -1)
		{
			set_reg(pc, reg, val);
			if (d->info & 4)
				ft_printf("P %4u | %s %d r%d\n", pc->id,
				g_op_tab[pc->opcode].name, val, reg);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
