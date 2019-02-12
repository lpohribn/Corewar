/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:37:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static int	calc_op(int opcode, int val1, int val2)
{
	if (opcode == 4)
		return (val1 + val2);
	else if (opcode == 5)
		return (val1 - val2);
	return (0);
}

void				arithmetic_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		reg[3];
	short int		offset;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		reg[0] = get_reg(d, pc, &offset);
		reg[1] = get_reg(d, pc, &offset);
		reg[2] = get_reg(d, pc, &offset);
		if (!pc->error)
		{
			set_reg(pc, reg[2], calc_op(pc->opcode,
			pc->reg[reg[0] - 1], pc->reg[reg[1] - 1]));
			if (d->info & 4)
				ft_printf("P %4u | %s r%d r%d r%d\n",
				pc->id, g_op_tab[pc->opcode].name, reg[0], reg[1], reg[2]);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
