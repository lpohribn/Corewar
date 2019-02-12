/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:26:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/07 17:26:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	static	void	ft_put_color(t_data_printf *d, char *str_color)
{
	t_bytes	*ptr_buff;
	t_bytes	*ptr_color;

	ptr_buff = (t_bytes*)&d->buff[d->buff_i];
	ptr_color = (t_bytes*)str_color;
	ptr_buff->byte7 = ptr_color->byte7;
	d->buff_i += 7;
	d->ret -= 7;
}

inline	static	int		ft_choose_color(t_data_printf *d, char *color, int chrs)
{
	t_bytes	*ptr;

	ptr = (t_bytes*)color;
	if (ptr->byte3 == EOC_CODE && chrs == 4)
		ft_put_color(d, PF_EOC);
	else if (ptr->byte3 == RED_CODE && chrs == 4)
		ft_put_color(d, PF_RED);
	else if (ptr->byte5 == GREEN_CODE && chrs == 6)
		ft_put_color(d, PF_GREEN);
	else if (ptr->byte6 == YELLOW_CODE && chrs == 7)
		ft_put_color(d, PF_YELLOW);
	else if (ptr->byte4 == BLUE_CODE && chrs == 5)
		ft_put_color(d, PF_BLUE);
	else if (ptr->byte6 == PURPLE_CODE && chrs == 7)
		ft_put_color(d, PF_PURPLE);
	else if (ptr->byte4 == CYAN_CODE && chrs == 5)
		ft_put_color(d, PF_CYAN);
	else if (ptr->byte5 == WHITE_CODE && chrs == 6)
		ft_put_color(d, PF_WHITE);
	else
		return (1);
	return (0);
}

const char				*ft_color(t_data_printf *d, const char *pos)
{
	int		i;
	char	str_col[7];

	i = 0;
	++pos;
	while (*(pos + i) && i < 7 && *(pos + i) != '}')
	{
		str_col[i] = *(pos + i);
		i++;
	}
	if (*(pos + i) != '}' || ft_choose_color(d, str_col, ++i))
	{
		if (FT_PRINTF_BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '{';
	}
	else
		pos += i;
	return (pos);
}
