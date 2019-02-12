/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadindex_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:59 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:37:59 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	print_info(t_process *const pc, int reg, int *val, int res)
{
	ft_printf("P %4u | %s %d %d r%d\n"
	"       | -> load from %d + %d = %d ", pc->id, g_op_tab[pc->opcode].name,
	val[0], val[1], reg, val[0], val[1], val[0] + val[1]);
	if (pc->opcode == 10)
		ft_printf("(with pc and mod %d)\n", pc->pos + res);
	else
		ft_printf("(with pc %d)\n", pc->pos + res);
}

void				loadindex_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		reg;
	short int		offset;
	int				val[2];
	int				res;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		val[0] = get_arg_val(d, pc, arg[0], &offset);
		val[1] = get_arg_val(d, pc, arg[1], &offset);
		reg = get_reg(d, pc, &offset);
		if (reg != -1 && !pc->error)
		{
			res = (val[0] + val[1]);
			if (pc->opcode == 10)
				res %= IDX_MOD;
			set_reg(pc, reg, get_arg(d, PC_POS(res), 4));
			if (d->info & 4)
				print_info(pc, reg, val, res);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
