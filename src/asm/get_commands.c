/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:24:41 by opletsan          #+#    #+#             */
/*   Updated: 2018/12/25 20:24:43 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline t_command	*add_command(t_data *d)
{
	t_command	*c;

	c = d->c;
	while (c->next && c->name)
		c = c->next;
	if (c->name && !(c->next = (t_command*)ft_memalloc(sizeof(t_command))))
		return (NULL);
	else if (c->name && c->next)
		c = c->next;
	return (c);
}

t_command				*get_command(t_data *d, char *s, int st, int end)
{
	t_command	*c;
	char		*command;
	int			j;

	j = 0;
	if (!(c = add_command(d)) ||
			!(command = ft_strsub(s, st, end - st)))
		d->error = -1;
	while (!d->error && ++j < NUM_OPERATION && !c->name)
		if (!ft_strcmp(command, g_op_tab[j].name))
		{
			c->line = ft_strdup(s);
			c->name = command;
			c->opcode = g_op_tab[j].opcode;
			c->f_codage = g_op_tab[j].codage;
			c->f_label = g_op_tab[j].label;
			++d->prog_size;
		}
	if (!d->error && !c->name)
	{
		d->error = 12;
		d->error_str = &s[st];
	}
	return (c);
}
