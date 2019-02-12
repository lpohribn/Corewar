/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_labels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:08:00 by opletsan          #+#    #+#             */
/*   Updated: 2018/11/25 21:08:01 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline t_label	*add_label(t_data *d)
{
	t_label *l;

	l = d->l;
	while (l->next && l->name)
		l = l->next;
	if (l->name && !(l->next = (t_label*)ft_memalloc(sizeof(t_label))))
	{
		d->error = -1;
		return (NULL);
	}
	else if (l->name && l->next)
		l = l->next;
	return (l);
}

static inline void		check_exist_labels(t_data *d, t_label *current, char *s)
{
	t_label	*begin;

	begin = d->l;
	while (begin != current)
	{
		if (ft_strequ(begin->name, current->name))
		{
			d->error = 11;
			d->error_str = s;
			break ;
		}
		begin = begin->next;
	}
}

void					get_label(t_data *d, char *s, int st, int end)
{
	t_label *l;
	int		start;

	start = st;
	if (!(l = add_label(d)))
		return ;
	while (st < end)
	{
		if (!ft_strchr(LABEL_CHARS, s[st]))
		{
			d->error = 10;
			d->error_str = &s[st];
			return ;
		}
		st++;
	}
	l->name = ft_strsub(s, start, end - start);
	l->address = d->prog_size + 1;
	check_exist_labels(d, l, &s[st]);
}
