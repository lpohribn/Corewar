/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_2ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:41:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/26 19:41:22 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_numline(const char *s, char c1, char c2)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c1 || *s == c2))
			s++;
		if (*s && *s != c1 && *s != c2)
			i++;
		while (*s && *s != c1 && *s != c2)
			s++;
	}
	return (i);
}

static inline size_t	ft_numlett(const char *s, unsigned int i,
														char c1, char c2)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c1 && s[i] != c2)
	{
		i++;
		len++;
	}
	return (len);
}

char					**ft_strsplit_2ch(const char *s, char c1, char c2)
{
	char	**res;
	char	**rres;
	size_t	i;

	i = 0;
	if (!s ||
			!(res = (char**)malloc(sizeof(char*) * ft_numline(s, c1, c2) + 1)))
		return (NULL);
	rres = res;
	while (s[i])
	{
		while (s[i] && (s[i] == c1 || s[i] == c2))
			i++;
		if (s[i] && s[i] != c1 && s[i] != c2)
		{
			*res = ft_strsub(s, i, ft_numlett(s, i, c1, c2));
			i += ft_numlett(s, i, c1, c2);
			res++;
		}
	}
	*res = NULL;
	return (rres);
}
