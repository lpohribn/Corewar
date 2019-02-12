/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:11:43 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/13 19:58:04 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		len_s;
	char	*str;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[len_s] == ' ' || s[len_s] == '\t' || s[len_s] == '\n' ||
			s[len_s] == '\0') && (size_t)len_s > i)
		len_s--;
	str = (char*)malloc(sizeof(char) * (len_s - i + 2));
	if (!str)
		return (NULL);
	while (i <= (size_t)len_s)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
