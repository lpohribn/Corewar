/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:13:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/12 19:13:45 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_arg_val(t_data *d, t_process *pc,
			unsigned char const arg, short int *offset)
{
	int			arg_val;
	const int	label = 4 >> g_op_tab[pc->opcode].label;

	if (arg == T_DIR)
	{
		arg_val = get_arg(d, PC_POS(*offset), label);
		*offset += label;
		if (label == 2)
			arg_val = (short)arg_val;
	}
	else if (arg == T_IND)
	{
		arg_val = (short)get_arg(d, PC_POS(*offset), 2);
		if (pc->opcode != 13 && pc->opcode != 14)
			arg_val %= IDX_MOD;
		arg_val = get_arg(d, PC_POS(arg_val), 4);
		*offset += 2;
	}
	else
	{
		if ((arg_val = get_reg(d, pc, offset)) == -1)
			return (-1);
		arg_val = pc->reg[arg_val - 1];
	}
	return (arg_val);
}
