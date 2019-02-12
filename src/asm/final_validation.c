/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:58:26 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/10 15:58:28 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	last_line(t_data *d, int len)
{
	char	buf[len + 1];
	int		i;

	i = 0;
	ft_bzero(buf, len + 1);
	if (lseek(d->fd, -len, SEEK_END) == -1L || read(d->fd, buf, len) < 0)
	{
		d->error = -1;
		return ;
	}
	if (buf[len - 1] != '\n')
	{
		if (buf[0] == '\n' && buf[1])
			i++;
		while (buf[i] && buf[i] != COMMENT_CHAR)
		{
			if (buf[i] != ' ' && buf[i] != '\t')
			{
				d->error = 18;
				return ;
			}
			i++;
		}
	}
}

static inline int	src_error_line(t_data *d, char *line, char *label)
{
	char	*buf;
	char	*cur;
	int		i;

	i = 0;
	buf = NULL;
	if (lseek(d->fd, 0, SEEK_SET) == -1L ||
			!(buf = ft_read_file(d->fd)))
	{
		d->error = -1;
		return (0);
	}
	ft_printf("|%s|\n", label);
	d->num_line = 0;
	cur = ft_strstr(buf, line);
	while (buf[i] && &buf[i] != cur)
	{
		if (buf[i] == '\n')
			++d->num_line;
		i++;
	}
	d->num_col = ft_strstr(line, label) - line;
	free(buf);
	return (0);
}

static inline int	check_labels(t_data *d, t_command *c)
{
	t_label	*l;
	int		i;

	while (c && c->name)
	{
		i = -1;
		while (c->a[++i].str_value)
			if (ft_strstr(c->a[i].str_value, "%:"))
			{
				l = d->l;
				while (l && l->name)
				{
					if (ft_strequ(l->name, &c->a[i].str_value[2]))
						break ;
					l = l->next;
				}
				if (!l || !l->name)
					return (src_error_line(d, c->line, c->a[i].str_value));
				else
					c->a[i].value = reverse_bytes(l->address - c->byte,
							DIR_SIZE >> g_op_tab[c->opcode].label);
			}
		c = c->next;
	}
	return (1);
}

static inline void	final_valid_contin(t_data *d)
{
	if (d->no_str && d->f == 'n')
		d->error = 2;
	else if (d->no_str && d->f == 'c')
		d->error = 3;
	else if (!d->no_str && d->f == 'n' && *d->name &&
			ft_strlen(d->name) > PROG_NAME_LENGTH + 1)
		d->error = 8;
	else if (!d->no_str && d->f == 'c' && *d->comment &&
			ft_strlen(d->comment) > COMMENT_LENGTH + 1)
		d->error = 9;
	else if (!*d->name)
		d->error = 4;
	else if (!*d->comment)
		d->error = 5;
	else if (!check_labels(d, d->c))
		d->error = 17;
	else
		last_line(d, ft_strlen(d->error_str) + 1);
}

void				final_valid(t_data *d, int ret)
{
	if (d->no_str)
	{
		d->num_col = 1;
		d->num_line++;
		ft_strdel(&d->error_str);
	}
	if (!d->no_str && ret == 0 && !d->error_str)
		d->error = 19;
	else if (ret < 0)
		d->error = -1;
	else
		final_valid_contin(d);
}
