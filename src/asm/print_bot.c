/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:55:43 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/13 17:55:46 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	print_bot_contin(t_command *c)
{
	int		i;

	i = 0;
	while (++i < MAX_ARGS_NUMBER && c->a[i].str_value)
	{
		if (!i)
			ft_printf("	");
		else
			ft_printf(", ");
		ft_printf("%s", c->a[i].str_value);
	}
	ft_printf("\n");
}

void				print_bot(t_data *d, t_label *l, t_command *c)
{
	int		i;
	t_label	*tmp;

	tmp = l;
	ft_printf("\nNAME: \"%s\"\nCOMMENT: \"%s\"\nSIZE = %d\n\n",
		d->name, d->comment, d->prog_size);
	while (c && c->name)
	{
		l = tmp;
		i = -1;
		while (l)
		{
			if (l->address == c->byte)
			{
				ft_printf("\n%s:\n", l->name);
				break ;
			}
			l = l->next;
		}
		ft_printf("	%s", c->name);
		print_bot_contin(c);
		c = c->next;
	}
	ft_printf("\n");
}
