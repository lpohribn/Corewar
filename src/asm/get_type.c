/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:07:00 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/12 13:07:02 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline _Bool	check_treg(char *s)
{
	int	i;

	i = 0;
	if (*s == 'r')
	{
		++s;
		if (!*s)
			return (0);
		while (s[i])
		{
			if (s[i] < '0' || s[i] > '9' || i > 1)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static inline _Bool	check_tdir(char *s)
{
	if (*s++ == '%')
	{
		if (!*s)
			return (0);
		else if (*s == ':')
		{
			++s;
			while (*s)
				if (!ft_strchr(LABEL_CHARS, *s++))
					return (0);
		}
		else if (*s)
		{
			if (*s == '-')
				++s;
			if (!*s)
				return (0);
			while (*s)
				if (*s < '0' || *s++ > '9')
					return (0);
		}
		return (1);
	}
	return (0);
}

static inline _Bool	check_tind(char *s)
{
	if (*s == '-')
		++s;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		++s;
		if (!*s)
			return (1);
	}
	return (0);
}

char				get_type(char *s)
{
	if (check_treg(s))
		return (T_REG);
	else if (check_tdir(s))
		return (T_DIR);
	else if (check_tind(s))
		return (T_IND);
	return (0);
}
