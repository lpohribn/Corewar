/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:09:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 10:09:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	init_data(t_data *d)
{
	d->cycle_to_die = CYCLE_TO_DIE;
	d->octets = 32;
	d->dump = -1;
	d->winner_id = -1;
}

inline static void	the_winner_is(t_data *d, const int winner_id)
{
	if (d->vis.isinit && isendwin() == false)
		endwin();
	if (winner_id != -1)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		d->player[winner_id].id, d->player[winner_id].prog_name);
	else
		ft_putendl("Hm... We have some problem... no"
		" player didn't report alive. This is a DRAW!");
}

int					main(const int argc, char const *argv[])
{
	t_data	d;

	ft_bzero(&d, sizeof(t_data));
	init_data(&d);
	if (argc == 1 || handle_arguments(&d, argc, argv + 1) < 0)
		usage(&d, *argv);
	if (d.server)
		server(&d);
	if (prepare_game(&d) < 0)
		usage(&d, *argv);
	game(&d);
	the_winner_is(&d, d.winner_id);
	xexit(&d, EXIT_SUCCESS);
}
