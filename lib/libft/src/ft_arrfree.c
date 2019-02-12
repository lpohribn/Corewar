/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:39:47 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/25 18:26:12 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrfree(void ***array)
{
	size_t	i;
	char	**cp;

	i = 0;
	if (!array || !*array)
		return ;
	cp = *(char***)array;
	while (cp[i])
	{
		free(cp[i]);
		cp[i] = NULL;
		i++;
	}
	free(cp);
	*(char***)array = NULL;
}
