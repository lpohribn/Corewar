/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_fnop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:02:07 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/28 20:02:08 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	(*const g_fnop[NUM_OPERATION])(t_data *d, t_process *const p) =
{
	0,
	live_op,
	load_op,
	st_op,
	arithmetic_op,
	arithmetic_op,
	bitwise_op,
	bitwise_op,
	bitwise_op,
	zjmp_op,
	loadindex_op,
	sti_op,
	fork_op,
	load_op,
	loadindex_op,
	fork_op,
	aff_op
};
