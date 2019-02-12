/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:18:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/22 20:18:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	handle_opcode(t_data *d, t_process *pc)
{
	const unsigned char	byte = d->memory[pc->pos];

	if (byte >= NUM_OPERATION || byte == 0)
		pc->pos = (pc->pos + 1) % MEM_SIZE;
	else
	{
		pc->run_cycles = g_op_tab[(int)byte].cycles;
		pc->opcode = d->memory[pc->pos];
	}
}

static inline void	pc_movement(t_data *d, t_process const *pc,
					const int pre_pos)
{
	const short int	pos_now = pc->pos;
	short int		i;

	ft_printf("ADV %d (0x%.4x -> 0x%.4x)",
	pos_now - pre_pos, pre_pos, pos_now);
	i = pre_pos;
	while (i < pos_now)
	{
		ft_printf(" %.2x", d->memory[i]);
		++i;
	}
	ft_putchar('\n');
}

static inline void	game_step(t_data *d)
{
	t_process	*pc;
	short int	pre_pos;

	pc = d->beg_pc;
	while (pc)
	{
		if (pc->run_cycles == -1)
			handle_opcode(d, pc);
		if (pc->run_cycles > 0)
			pc->run_cycles--;
		if (pc->run_cycles == 0)
		{
			pc->run_cycles = -1;
			pre_pos = pc->pos;
			g_fnop[pc->opcode](d, pc);
			if (d->info & 16 && pc->opcode != 9)
				pc_movement(d, pc, pre_pos);
			pc->opcode = undefined;
			pc->error = 0;
		}
		pc = pc->next;
	}
}

static inline void	time_to_die(t_data *d, int *when_to_die)
{
	t_process	*pc;
	static int	max_checks = 0;

	pc = d->beg_pc;
	++max_checks;
	while (pc)
	{
		if (!pc->live || d->cycle_to_die < 0)
		{
			delete_pc(d, &pc);
			continue ;
		}
		else
			pc->live = 0;
		pc = pc->next;
	}
	if (d->execution_live >= NBR_LIVE || max_checks == MAX_CHECKS)
	{
		d->cycle_to_die -= CYCLE_DELTA;
		max_checks = 0;
		if (d->info & 6)
			ft_printf("Cycle to die is now %d\n", d->cycle_to_die);
	}
	d->execution_live = 0;
	*when_to_die += d->cycle_to_die;
}

int					game(t_data *d)
{
	int	when_to_die;

	when_to_die = d->cycle_to_die;
	while (d->num_processes)
	{
		++d->cur_cycle;
		if (d->info & 2)
			ft_printf("It is now cycle %d\n", d->cur_cycle);
		game_step(d);
		if (when_to_die <= d->cur_cycle)
		{
			break_plives(d);
			time_to_die(d, &when_to_die);
		}
		if (d->dump == d->cur_cycle)
			dump_memory(d);
		if (d->visual_mode)
			while (visualization(d))
				;
	}
	return (0);
}
