/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:34:09 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/07 20:34:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					handle_file(t_data *d, const char *filename, _Bool check)
{
	if (!filename)
	{
		ft_dprintf(2, "corewar: no file name\n");
		return (-1);
	}
	if (check && ft_strcmp(filename + (ft_strlen(filename) - 4), ".cor"))
	{
		ft_dprintf(2, "corewar: %s: Invalid champion's name\n", filename);
		return (-1);
	}
	if (d->num_players == MAX_PLAYERS)
		xerror(d, NULL, 3);
	handle_champion(d, filename);
	d->num_players++;
	return (0);
}
