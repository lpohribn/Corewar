/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:36:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:36:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static int	calc_bit_op(int opcode, int val1, int val2)
{
	if (opcode == 6)
		return (val1 & val2);
	else if (opcode == 7)
		return (val1 | val2);
	else if (opcode == 8)
		return (val1 ^ val2);
	return (0);
}

void				bitwise_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	int				val[2];
	short int		reg;
	short int		offset;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		val[0] = get_arg_val(d, pc, arg[0], &offset);
		val[1] = get_arg_val(d, pc, arg[1], &offset);
		reg = get_reg(d, pc, &offset);
		if (reg != -1 && !pc->error)
		{
			set_reg(pc, reg, calc_bit_op(pc->opcode, val[0], val[1]));
			if (d->info & 4)
				ft_printf("P %4u | %s %d %d r%d\n", pc->id,
				g_op_tab[pc->opcode].name, val[0], val[1], reg);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
