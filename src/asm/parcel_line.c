/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcel_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 05:43:49 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/13 05:43:52 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int	parcel_line1(t_data *d, char *line, int *i)
{
	int		j;

	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	j = *i;
	if (!line[j] || line[j] == COMMENT_CHAR)
		return (-1);
	while (line[j] && line[j] != ' ' && line[j] != '\t' &&
			line[j] != LABEL_CHAR)
	{
		if (line[j] == COMMENT_CHAR)
		{
			d->error = 10;
			d->error_str = &line[j];
			return (j);
		}
		j++;
	}
	if (!line[j])
	{
		d->error = 10;
		d->error_str = &line[j];
	}
	return (j);
}

static inline void	parcel_line2(t_data *d, t_command *c, char *line, int j)
{
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (!line[j] || line[j] == COMMENT_CHAR)
	{
		d->error = 10;
		d->error_str = &line[j];
	}
	if (!d->error && get_arguments(d, c, line, j) != g_op_tab[c->opcode].argc)
	{
		d->error = 14;
		d->error_str = &line[j];
	}
	if (!d->error)
		save_data(d, c);
}

void				parcel_line(t_data *d, char *line)
{
	t_command	*c;
	int			i;
	int			j;

	c = NULL;
	i = 0;
	j = parcel_line1(d, line, &i);
	if (j > 0 && !d->error && line[j] == LABEL_CHAR)
	{
		get_label(d, line, i, j);
		if (d->error)
			return ;
		i = ++j;
		j = parcel_line1(d, line, &i);
	}
	if (j > 0 && !d->error)
		c = get_command(d, line, i, j);
	if (j > 0 && !d->error)
		parcel_line2(d, c, line, j);
}
