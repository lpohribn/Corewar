/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:54:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 13:54:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(const char **str, int *nbr)
{
	const char	*cp = *str;
	int			sign;
	int			num;

	if (!str)
		return (-1);
	sign = 1;
	num = 0;
	while (*cp && (*cp < '0' || *cp > '9' ||
		(*cp == '-' && *(cp + 1) >= '0' && *(cp + 1) <= '9')))
		cp++;
	if (*cp == '-' || *cp == '+')
		sign = 44 - *cp++;
	if (*cp < '0' || *cp > '9')
		return (0);
	while (*cp >= '0' && *cp <= '9')
		num = num * 10 + (*cp++ - '0');
	if (nbr)
		*nbr = num * sign;
	*str = cp;
	return (1);
}
