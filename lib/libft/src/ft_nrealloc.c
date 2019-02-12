/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:15:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/22 15:15:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_nrealloc(void *ptr, size_t plen, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, plen);
	return (new);
}
