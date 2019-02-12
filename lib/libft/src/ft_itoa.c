/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:08:26 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/12 14:40:36 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		d;
	char		*str;
	long long	nbr;

	nbr = n;
	d = ft_count_digits(n);
	str = (n >= 0 ? (char*)malloc(sizeof(char) * d + 1) :
			(char*)malloc(sizeof(char) * ++d + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	str[d] = '\0';
	while (d-- > 0)
	{
		str[d] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
