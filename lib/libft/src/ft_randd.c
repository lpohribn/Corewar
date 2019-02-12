/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:28:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/07 14:28:25 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_randd(double min, double max)
{
	double	scale;

	scale = rand() / (double)RAND_MAX;
	return (min + scale * (max - min));
}
