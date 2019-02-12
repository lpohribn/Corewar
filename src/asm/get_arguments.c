/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:19:04 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/11 16:19:06 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int	check_separator_char(t_data *d, char *s, int st)
{
	int		flag;

	flag = 0;
	while (s[st] && (s[st] == ' ' || s[st] == '\t' ||
			s[st] == SEPARATOR_CHAR))
	{
		if (s[st] == SEPARATOR_CHAR && !flag)
			flag = st;
		else if (s[st] == SEPARATOR_CHAR && flag)
		{
			d->error = 16;
			d->error_str = &s[st];
			return (st);
		}
		st++;
	}
	if ((flag && !s[st]) || (!flag && s[st] && s[st] != COMMENT_CHAR))
	{
		d->error = 10;
		d->error_str = &s[st];
	}
	return (st);
}

int					get_arguments(t_data *d, t_command *c, char *s, int st)
{
	int		end;
	int		i;

	i = 0;
	while (!d->error && i < MAX_ARGS_NUMBER && s[st] && s[st] != COMMENT_CHAR)
	{
		end = st;
		while (s[end] && s[end] != ' ' && s[end] != '\t' &&
				s[end] != COMMENT_CHAR && s[end] != SEPARATOR_CHAR)
			end++;
		if (!(c->a[i].str_value = ft_strsub(s, st, end - st)))
			d->error = -1;
		else if (!(c->a[i].type = get_type(c->a[i].str_value)) ||
				!(c->a[i].type & g_op_tab[c->opcode].argv[i]))
			d->error = 13;
		else
			i++;
		if (!d->error)
			st = check_separator_char(d, s, end);
		else
			d->error_str = &s[st];
	}
	return (i);
}
