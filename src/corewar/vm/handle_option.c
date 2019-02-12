/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:39:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 18:39:31 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	get_nbr(const char *str_nbr, int *ptr_to_nbr)
{
	unsigned long int	nbr;

	if (!str_nbr)
	{
		ft_dprintf(2, "corewar: no number\n");
		return (-1);
	}
	if (*str_nbr == '+')
		str_nbr++;
	else if (*str_nbr == '-' && '0' <= *(str_nbr + 1) && *(str_nbr + 1) <= '9')
	{
		ft_dprintf(2, "corewar: number must be a positive\n");
		return (-1);
	}
	nbr = 0;
	while ('0' <= *str_nbr && *str_nbr <= '9' && nbr < MAX_PLAYER_ID)
		nbr = nbr * 10 + (*str_nbr++ - '0');
	if (!*str_nbr && nbr < MAX_PLAYER_ID)
	{
		*ptr_to_nbr = (unsigned int)nbr;
		return (1);
	}
	ft_dprintf(2, "corewar: invalid number\n");
	return (-1);
}

static inline int	get_option(t_data *d, const char *options)
{
	char	op;

	while (*++options)
	{
		op = *options;
		if (op == 'v')
			d->visual_mode = true;
		else if (op == 'l')
			d->leaks = true;
		else if (op == 'p')
			d->p_flag = true;
		else if (op == 's')
			d->server = true;
		else if (op == 'a')
			d->aff_print = true;
		else
		{
			if (op == 'h')
				d->help = true;
			else
				ft_printf("corewar: illegal option -- %c\n", op);
			return (-1);
		}
	}
	return (0);
}

int					handle_option(t_data *d, const char *argv[])
{
	const char	*options = *argv;

	if (!ft_strcmp(options, "--dump") || !ft_strcmp(options, "-d"))
		return (get_nbr(*(argv + 1), &d->dump));
	else if (!ft_strcmp(options, "-n"))
		return (get_nbr(*(argv + 1), &d->num));
	else if (!ft_strcmp(options, "--octet") || !ft_strcmp(options, "-o"))
		return (get_nbr(*(argv + 1), &d->octets));
	else if (!ft_strcmp(options, "--info") || !ft_strcmp(options, "-i"))
		return (get_nbr(*(argv + 1), &d->info));
	else if (!ft_strcmp(options, "--help") || !ft_strcmp(options, "-help"))
	{
		d->help = true;
		return (-1);
	}
	else if (!ft_strcmp(options, "-name"))
		return (handle_file(d, *(argv + 1), 0) + 1);
	else if (!ft_strcmp(options, "--server"))
	{
		d->server = true;
		return (0);
	}
	else if (!ft_strcmp(options, "--client") || !ft_strcmp(options, "-c"))
		return (client(d, (argv + 1)));
	return (get_option(d, options));
}
