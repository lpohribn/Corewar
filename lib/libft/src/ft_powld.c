/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:18:52 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/27 12:18:52 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double		ft_powld(long double val, int pow)
{
	long double		res;

	res = 1l;
	if (pow < 0)
		return (0);
	while (pow > 0)
	{
		if (pow & 1)
			res *= val;
		val *= val;
		pow >>= 1;
	}
	return (res);
}
