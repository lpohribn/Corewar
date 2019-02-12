/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:24:50 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/12 19:24:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_reg(t_process *p, const int reg, const int val)
{
	p->reg[reg - 1] = val;
	if (p->opcode != st && p->opcode != ldi)
	{
		if (p->reg[reg - 1] == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}
