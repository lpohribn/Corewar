/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:37:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff_op(t_data *d, t_process *const pc)
{
	unsigned char	arg[MAX_ARGS_NUMBER];
	short int		reg;
	short int		offset;
	unsigned char	aff;

	offset = 2;
	if (hanlde_codage(arg, pc->opcode, d->memory[PC_POS(1)]) == 0)
	{
		reg = get_reg(d, pc, &offset);
		if (reg != -1 && d->aff_print && d->visual_mode == false)
		{
			aff = (unsigned char)(pc->reg[reg - 1] % 256);
			ft_printf("Aff: %c\n", aff);
		}
	}
	change_pc_pos(pc, pc->opcode, arg);
}
