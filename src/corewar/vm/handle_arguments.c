/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:25:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 10:25:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		handle_arguments(t_data *d, const int argc, char const *argv[])
{
	int	i;
	int	ret;

	i = 0;
	while (i < argc - 1)
	{
		if (*argv[i] == '-' && *(argv[i] + 1))
		{
			if ((ret = handle_option(d, &argv[i])) < 0)
				return (-1);
			i += ret;
		}
		else if (handle_file(d, argv[i], 1) < 0)
			return (-1);
		++i;
	}
	return (0);
}
