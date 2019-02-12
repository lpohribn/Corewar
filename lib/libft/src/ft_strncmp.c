/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:57:31 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/13 19:49:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
			s1[i] != '\0' && i < n - 1)
		i++;
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
