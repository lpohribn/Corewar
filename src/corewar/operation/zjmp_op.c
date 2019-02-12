/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:36:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/23 16:36:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp_op(t_data *d, t_process *const pc)
{
	short int		new_pos;
	char			*str_success;

	str_success = "FAILED";
	new_pos = (short)get_arg(d, PC_POS(1), 2);
	if (pc->carry)
	{
		pc->pos = PC_POS(new_pos % IDX_MOD);
		str_success = "OK";
	}
	else
		pc->pos = PC_POS(1 + T_DIR);
	if (d->info & 4)
		ft_printf("P %4u | %s %d %s\n", pc->id,
		g_op_tab[pc->opcode].name, new_pos, str_success);
}
