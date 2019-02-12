/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:38:45 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	put_reg_val(t_data *d, t_process *const pc,
					unsigned char *arg, short int reg)
{
	short int	to;
	short int	offset;

	offset = 3;
	if (arg[1] == T_REG)
	{
		to = get_reg(d, pc, &offset);
		if (to != -1)
			set_reg(pc, to, pc->reg[reg - 1]);
	}
	else
	{
		to = (short)get_arg(d, PC_POS(3), 2);
		set_memory(pc, d, PC_POS(to % IDX_MOD), pc->reg[reg - 1]);
	}
	if (d->info & 4 && !pc->error)
		ft_printf("P %4u | %s r%d %d\n", pc->id, g_op_tab[pc->opcode].name,
		reg, to);
}

void				st_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		reg;
	short int		offset;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		reg = get_reg(d, pc, &offset);
		if (reg != -1)
			put_reg_val(d, pc, arg, reg);
	}
	change_pc_pos(pc, pc->opcode, arg);
}
