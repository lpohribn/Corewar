/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:42:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/01/16 19:58:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static int	ft_check(int str_base, char ch)
{
	int		nbr;
	char	check;

	check = 'A';
	nbr = 10;
	if (ch >= '0' && ch <= '9')
	{
		if (ch - '0' < str_base)
			return (ch - '0');
		else
			return (-1);
	}
	if (ch >= 'a' && ch <= 'f')
		ch = ch - (char)32;
	while (nbr < 16 && nbr < str_base)
	{
		if (check++ == ch)
			return (nbr);
		nbr++;
	}
	return (-1);
}

inline static int	ft_strpow_base(const char *str, int str_base)
{
	int len;

	len = 0;
	while (*str != '\0' && (ft_check(str_base, *str) != -1))
	{
		str++;
		len++;
	}
	return (len);
}

int					ft_atoi_base(const char *str, int str_base)
{
	int				nbr;
	int				sign;
	int				c;
	int				pow;

	sign = 1;
	nbr = 0;
	if (!str && str_base < 2)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\r' ||
			*str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	pow = ft_strpow_base(str, str_base) - 1;
	while (*str != '\0' && (c = ft_check(str_base, *str)) != -1)
	{
		nbr = nbr + (ft_pow(str_base, pow) * c);
		pow--;
		str++;
	}
	return (nbr * sign);
}
