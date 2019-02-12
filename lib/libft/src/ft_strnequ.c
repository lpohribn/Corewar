/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:48:04 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/12 16:27:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!n)
		return (1);
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || i == n - 1)
			return (1);
		i++;
	}
	return (0);
}
