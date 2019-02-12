/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pc_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:18:36 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/06 15:18:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	change_pc_pos(t_process *const pc, unsigned char const opcode,
		unsigned char *arg)
{
	const int	nbr_arg = g_op_tab[opcode].argc;
	int			i;
	int			offset;

	i = 0;
	offset = 2;
	while (i < nbr_arg)
	{
		if (arg[i] == T_REG)
			offset += 1;
		else if (arg[i] == T_DIR)
			offset += DIR_SIZE >> g_op_tab[opcode].label;
		else if (arg[i] == T_IND)
			offset += IND_SIZE;
		++i;
	}
	pc->pos = PC_POS(offset);
}
