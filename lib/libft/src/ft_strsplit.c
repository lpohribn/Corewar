/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:10:40 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/15 14:51:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static size_t	ft_letters(char const *s, char c)
{
	int		letters;

	letters = 0;
	while (s[letters] != c && s[letters] != '\0')
		letters++;
	return (letters);
}

inline static char		*ft_copy(char *dest, char const *s, char c)
{
	while (*s != '\0' && *s != c)
		*dest++ = *s++;
	*dest = '\0';
	return ((char*)s);
}

char					**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			i;
	int			words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = -1;
	while (words > ++i)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(arr[i] = (char*)malloc(sizeof(char) * ft_letters(s, c) + 1)))
		{
			ft_arrfree((void*)&arr);
			return (NULL);
		}
		s = ft_copy(arr[i], s, c);
	}
	arr[i] = NULL;
	return (arr);
}
