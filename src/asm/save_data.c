/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 06:59:48 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/13 06:59:50 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	get_codage(t_command *c)
{
	unsigned char	codage;
	int				i;

	i = 0;
	codage = 0;
	while (i < g_op_tab[c->opcode].argc)
	{
		if (c->a[i].type == T_REG)
			codage |= REG_CODE << (MAX_ARGS_NUMBER - 1 - i) * 2;
		else if (c->a[i].type == T_DIR)
			codage |= DIR_CODE << (MAX_ARGS_NUMBER - 1 - i) * 2;
		else if (c->a[i].type == T_IND)
			codage |= IND_CODE << (MAX_ARGS_NUMBER - 1 - i) * 2;
		++i;
	}
	c->codage = codage;
}

unsigned int		reverse_bytes(unsigned int value, int bytes)
{
	unsigned int	rev;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&value;
	n2 = (unsigned char *)&rev;
	if (bytes == 2)
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	else if (bytes == 4)
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	return (rev);
}

static inline void	calculate_size(t_data *d, t_arg *a, _Bool label)
{
	if (a->type == T_REG)
		d->prog_size += T_REG;
	else if (a->type == T_DIR)
		d->prog_size += DIR_SIZE >> label;
	else if (a->type == T_IND)
		d->prog_size += IND_SIZE;
}

void				save_data(t_data *d, t_command *c)
{
	int		i;

	i = 0;
	c->byte = d->prog_size;
	if (c->f_codage)
	{
		get_codage(c);
		d->prog_size++;
	}
	while (c->a[i].type)
	{
		if (c->a[i].type == T_REG)
			c->a[i].value = ft_atoi(&c->a[i].str_value[1]);
		else if (c->a[i].type == T_DIR && c->a[i].str_value[1] != ':')
			c->a[i].value = reverse_bytes(ft_atoi(&c->a[i].str_value[1]),
					DIR_SIZE >> g_op_tab[c->opcode].label);
		else if (c->a[i].type == T_IND)
			c->a[i].value = (unsigned short int)reverse_bytes(ft_atoi(
					c->a[i].str_value), IND_SIZE);
		calculate_size(d, &c->a[i], g_op_tab[c->opcode].label);
		i++;
	}
}
