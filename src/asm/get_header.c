/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:54:49 by opletsan          #+#    #+#             */
/*   Updated: 2018/11/15 17:54:51 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline char	*some_check(t_data *d, char *s)
{
	if (s == ft_strstr(s, NAME_CMD_STRING))
		d->f = 'n';
	else if (s == ft_strstr(s, COMMENT_CMD_STRING))
		d->f = 'c';
	else
	{
		d->error = 10;
		return (s);
	}
	if (d->f == 'n')
		s += 5;
	else if (d->f == 'c')
		s += 8;
	if (d->f == 'n' && *d->name)
		d->error = 6;
	else if (d->f == 'c' && *d->comment)
		d->error = 7;
	else if (!*s && d->f == 'n')
		d->error = 4;
	else if (!*s && d->f == 'c')
		d->error = 5;
	return (s);
}

static inline char	*prev_valid(t_data *d, char *s)
{
	while (*s && *s != '.')
	{
		if (*s == COMMENT_CHAR)
			return (NULL);
		else if (*s != ' ' && *s != '\t')
			break ;
		s++;
	}
	s = some_check(d, s);
	while (!d->error && *s && *s != '"')
	{
		if (*s == COMMENT_CHAR && d->f == 'n')
			d->error = 4;
		else if (*s == COMMENT_CHAR && d->f == 'c')
			d->error = 5;
		else if (*s != ' ' && *s != '\t')
			d->error = 10;
		if (d->error)
			break ;
		s++;
	}
	if (d->error)
		return (d->error_str = s);
	return (++s);
}

static inline void	valid_name_or_comment(t_data *d, char *s, int *l)
{
	char	*end;

	end = NULL;
	if ((end = ft_strchr(s, '"')))
	{
		*l = end - s;
		while (!d->error && *(++end) && *end != COMMENT_CHAR)
			if (*end != ' ' && (*end < 9 || *end > 13))
			{
				d->error = 10;
				d->error_str = end;
			}
		d->no_str = 0;
	}
	else
	{
		*l = ft_strlen(s);
		d->no_str = 1;
		d->error_str = ft_strchr(s, '\0');
	}
}

static inline void	save_name_or_comment(t_data *d, char *s, int l)
{
	char	*tmp1;
	char	*tmp2;

	tmp2 = ft_strsub(s, 0, l);
	if (!l)
		tmp2[0] = 3;
	if (d->no_str)
	{
		tmp1 = tmp2;
		tmp2 = ft_strjoin(tmp1, "\n");
		free(tmp1);
	}
	if (d->f == 'n')
	{
		tmp1 = d->name;
		d->name = ft_strjoin(tmp1, tmp2);
	}
	else if (d->f == 'c')
	{
		tmp1 = d->comment;
		d->comment = ft_strjoin(tmp1, tmp2);
	}
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
}

void				get_name_or_comment(t_data *d, char *s)
{
	int		l;

	l = 0;
	if (!d->no_str)
		s = prev_valid(d, s);
	if (!d->error && d->f && s)
	{
		valid_name_or_comment(d, s, &l);
		if (!d->error)
			save_name_or_comment(d, s, l);
	}
}
