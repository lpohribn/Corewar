/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:18:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/01/26 15:18:37 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revstr(char *str)
{
	unsigned int		len;
	unsigned int		i;
	char				tmp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (len / 2 >= i)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
}
