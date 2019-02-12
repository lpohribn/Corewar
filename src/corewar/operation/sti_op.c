/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:38:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		offset;
	short int		reg;
	int				val1;
	int				val2;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		reg = get_reg(d, pc, &offset);
		val1 = get_arg_val(d, pc, arg[1], &offset);
		val2 = get_arg_val(d, pc, arg[2], &offset);
		if (reg != -1 && !pc->error)
		{
			set_memory(pc, d, PC_POS((val1 + val2) % IDX_MOD),
			pc->reg[reg - 1]);
			if (d->info & 4)
				ft_printf("P %4u | %s r%d %d %d\n"
				"       | -> store to %d + %d = %d (with pc and mod %d)\n",
				pc->id, g_op_tab[pc->opcode].name, reg, val1, val2, val1,
				val2, val1 + val2, pc->pos + (val1 + val2) % IDX_MOD);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
