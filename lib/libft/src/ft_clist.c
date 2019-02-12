/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:44:40 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/15 13:21:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_clist(t_list *begin)
{
	size_t i;

	i = 0;
	if (!begin)
		return (0);
	while (begin != NULL)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}
