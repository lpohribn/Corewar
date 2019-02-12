/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_codage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:41:01 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/06 14:41:03 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	valid_codage(unsigned char *arg,
					unsigned char const opcode, const int nbr_arg)
{
	const t_arg_type	*argv = g_op_tab[opcode].argv;
	int					i;

	i = 0;
	while (i < nbr_arg)
	{
		if ((argv[i] & arg[i]) == 0)
			return (-1);
		++i;
	}
	return (0);
}

int					hanlde_codage(unsigned char *arg,
					unsigned char const opcode, unsigned char const codage)
{
	const int	nbr_arg = g_op_tab[opcode].argc;
	int			i;
	int			shift;

	i = 0;
	while (i < nbr_arg)
	{
		shift = ((codage >> (MAX_ARGS_NUMBER - 1 - i) * 2) & 0x3);
		arg[i] = 1 << (shift - 1);
		++i;
	}
	return (valid_codage(arg, opcode, nbr_arg));
}
