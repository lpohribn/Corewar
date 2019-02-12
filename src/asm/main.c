/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:35:42 by opletsan          #+#    #+#             */
/*   Updated: 2018/11/06 17:35:44 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	free_data(t_data *d)
{
	void	*tmp;
	int		i;

	while (d->l)
	{
		tmp = d->l->next;
		ft_strdel(&d->l->name);
		d->l->address = 0;
		free(d->l);
		d->l = tmp;
	}
	while (d->c)
	{
		i = -1;
		tmp = d->c->next;
		ft_strdel(&d->c->line);
		ft_strdel(&d->c->name);
		while (++i < MAX_ARGS_NUMBER)
			ft_strdel(&d->c->a[i].str_value);
		free(d->c);
		d->c = tmp;
	}
	ft_strdel(&d->name);
	ft_strdel(&d->comment);
	ft_strdel(&d->file_name);
}

static inline void	token_info(t_data *d, char *line)
{
	int			i;
	t_command	*c;

	i = 0;
	c = d->c;
	d->num_col = 1;
	if (d->error && (d->error == 4 || d->error == 5 ||
			(d->error >= 10 && d->error <= 16)))
		d->num_col = d->error_str - line + 1;
	else if (d->no_str)
		d->num_col = ft_strlen(line) + 1;
	d->error_str = ft_strdup(line);
}

static inline void	read_file(t_data *d)
{
	char	*line;
	int		ret;

	line = NULL;
	while (!d->error && (ret = get_next_line(d->fd, &line)) > 0)
	{
		ft_strdel(&d->error_str);
		++d->num_line;
		if (*line != COMMENT_CHAR && (*line || (!*line && d->no_str)))
		{
			if (!*d->name || !*d->comment || d->no_str)
				get_name_or_comment(d, line);
			else
				parcel_line(d, line);
		}
		token_info(d, line);
		free(line);
	}
	if (!d->error)
		final_valid(d, ret);
}

static inline void	open_file(t_data *d, char *arg)
{
	int		len;
	char	*tmp;

	d->name = ft_strnew(1);
	d->comment = ft_strnew(1);
	if (!(d->c = (t_command*)ft_memalloc(sizeof(t_command))) ||
			!(d->l = (t_label*)ft_memalloc(sizeof(t_label))))
	{
		d->error = -1;
		return ;
	}
	len = ft_strlen(arg);
	if (!(d->file_name = ft_strsub(arg, 0, len - 1)) ||
			(d->fd = open(arg, O_RDONLY)) < 0 || read(d->fd, 0, 0) < 0)
		d->error = -1;
	else if (arg[len - 1] != 's' && arg[len - 2] != '.')
		d->error = 1;
	if (!d->error && d->file_name)
	{
		tmp = d->file_name;
		if (!(d->file_name = ft_strjoin(tmp, "cor")))
			d->error = -1;
		free(tmp);
	}
}

int					main(int ac, char **av)
{
	t_data	d;
	size_t	i;

	i = 0;
	g_flag = 0;
	if (ac == 1)
		ft_putstr("Usage: ./asm [-a] <sourcefile.s ...>\n   -a : show bot\n");
	else
		while (av[++i])
		{
			if (ft_strequ(av[i], "-a"))
				g_flag = 1;
			else
			{
				ft_bzero(&d, sizeof(t_data));
				open_file(&d, av[i]);
				read_file(&d);
				if (!d.error)
					write_file(&d);
				ft_error(&d, av[i]);
				free_data(&d);
				close(d.fd);
			}
		}
	return (0);
}
