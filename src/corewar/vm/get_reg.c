/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:19:01 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/12 19:19:25 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short int		get_reg(t_data *d, t_process *pc, short int *offset)
{
	short int	reg;

	reg = d->memory[PC_POS(*offset)];
	++(*offset);
	if (reg > 0 && reg <= REG_NUMBER)
		return (reg);
	pc->error = 1;
	return (-1);
}
