/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:48:36 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/26 15:48:37 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrnfree(void ***array, size_t len)
{
	size_t	i;
	char	**cp;

	i = 0;
	if (!array)
		return ;
	cp = *(char***)array;
	while (i < len)
	{
		free(cp[i]);
		cp[i] = NULL;
		i++;
	}
	free(cp);
	*(char***)array = NULL;
}
