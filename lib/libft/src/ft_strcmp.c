/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:11:13 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/13 19:02:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);

	if (!len_s2 || !len_s1)
		return (*s1 - *s2);
	if (len_s1 < len_s2)
		return (ft_memcmp((void*)s1, (void*)s2, len_s1 + 1));
	else
		return (ft_memcmp((void*)s1, (void*)s2, len_s2 + 1));
}
