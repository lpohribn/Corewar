/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:20:55 by rnovodra          #+#    #+#             */
/*   Updated: 2019/01/07 20:20:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_help(void)
{
	ft_dprintf(STDERR_FILENO, "    -p%17: increase possible N in -n option\n"
	"    -l                : at the end of program, execute program leaks\n"
	"    -a                : Prints output from \"aff\" "
	"(Default is to hide it)\n"
	"    -name filename    : name of file, corewar don't validate the name\n"
	"    -n N              : player id N(1 - %d)\n"
	"    -o | --octets N   : N octets per line using dump\n"
	"****************INFORMATION OUTPUT********************************\n"
	"    -d | --dump N     : Dumps memory after N cycles then exits\n"
	"    -i | --info N     : Verbosity levels, can be added "
	"together to enable several\n"
	"			  - 0 : Show only essentials\n"
	"			  - 1 : Show lives\n"
	"			  - 2 : Show cycles\n"
	"			  - 6 : Show operations (Params are NOT litteral ...)\n"
	"			  - 8 : Show deaths\n"
	"			  - 16 : Show PC movements (Except for jumps)\n"
	"****************VISUAL MODE****************************************\n"
	"    -v                : ncurses mode on, disable all output options\n"
	"****************NETWORK MODE***************************************\n"
	"    -s | --server    [champname.cor]: create server with bot or not, "
	"this options turn in visual mode\n"
	"    -c | --client IP [champname.cor]: connect client to the server "
	"IP(0.0.0.0.0), with champion like a player, without like a viewer\n",
	MAX_PLAYERS);
}

void				usage(t_data *d, const char *prog_name)
{
	if (d->vis.isinit)
		endwin();
	ft_dprintf(STDERR_FILENO, "usage: %s [-ahlpsv] [-d | --dump N] [-n N]"
	" [-o | --octets N] [-i | --info N] [-help | --help] [-name filename] "
	"<champname.cor ...>\n", prog_name);
	if (d->help)
		print_help();
	else
		ft_putendl("Use -h | -help | --help for more information "
		"about options");
	xexit(d, EXIT_FAILURE);
}
