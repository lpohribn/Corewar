/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:08:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/06 18:08:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_get_rvalue(int color)
{
	return (color >> 16 & 0xFF);
}

static inline int	ft_get_gvalue(int color)
{
	return (color >> 8 & 0xFF);
}

static inline int	ft_get_bvalue(int color)
{
	return (color & 0xFF);
}

static inline int	ft_color(int f_color, int s_color, double procent)
{
	return ((int)(f_color + (s_color - f_color) * procent));
}

int					ft_gradient(int f_color, int s_color, double procent)
{
	int r;
	int g;
	int b;

	if (f_color == s_color)
		return ((int)f_color);
	r = ft_color(ft_get_rvalue((int)f_color),
		ft_get_rvalue((int)s_color), procent);
	g = ft_color(ft_get_gvalue((int)f_color),
		ft_get_gvalue((int)s_color), procent);
	b = ft_color(ft_get_bvalue((int)f_color),
		ft_get_bvalue((int)s_color), procent);
	return (r << 16 | g << 8 | b);
}
