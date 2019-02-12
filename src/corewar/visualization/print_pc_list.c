/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:05:38 by lpohribn          #+#    #+#             */
/*   Updated: 2018/12/27 16:05:40 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	turn_on_color_of_pc(WINDOW *win, t_process *pc,
					t_process *select, int status)
{
	if (status)
	{
		if (pc == select)
			wattron(win, COLOR_PAIR(BLACK_ORANGE));
		else
			wattron(win, COLOR_PAIR(pc->which_player));
	}
	else
	{
		if (pc == select)
			wattroff(win, COLOR_PAIR(BLACK_ORANGE));
		else
			wattroff(win, COLOR_PAIR(pc->which_player));
	}
}

static inline void	select_reg(t_data *d, t_process *pc)
{
	int i;
	int coord_y;

	coord_y = 59;
	i = 0;
	while (i < REG_NUMBER)
	{
		if (i < REG_NUMBER / 2)
			mvwprintw(d->vis.win, i + coord_y, 198,
			"Register[%1d] = %10x", i, pc->reg[i]);
		else
			mvwprintw(d->vis.win, (coord_y - 8) + (i - (REG_NUMBER / 2)), 242,
			"Register[%2d] = %10x", i, pc->reg[i]);
		coord_y++;
		++i;
	}
}

static inline void	print_pc_line(WINDOW *win, t_process *pc,
					t_process *select, int y)
{
	char	c1;
	char	c2;

	c1 = ' ';
	c2 = ' ';
	if (pc->live)
		c1 = 'L';
	if (pc->carry)
		c2 = 'C';
	turn_on_color_of_pc(win, pc, select, 1);
	if (!pc->opcode)
		mvwprintw(win, y, 198, "#%8-d    %2dx%-2d   [P%d] [%c][%c]   %-23s %5s",
		pc->id, pc->pos / 64 + 1, pc->pos % 64 + 1, pc->which_player, c1, c2,
		"looking for command", "...");
	else
	{
		mvwprintw(win, y, 198, "#%-8d    %2dx%-2d   [P%d] [%c][%c]   %-23s %5s",
		pc->id, pc->pos / 64 + 1, pc->pos % 64 + 1, pc->which_player, c1, c2,
		"executing the command", g_op_tab[pc->opcode]);
		mvwprintw(win, y, 262, " (%d)", pc->run_cycles);
	}
	turn_on_color_of_pc(win, pc, select, 0);
}

static inline int	calc_average(t_data *d, t_process *select_pc, const int pos)
{
	int			num_prev;
	int			num_next;
	t_process	*pc;

	num_prev = 0;
	pc = select_pc->prev;
	while (pc && ++num_prev < NUM_PRINT_PC)
		pc = pc->prev;
	num_next = 0;
	pc = select_pc->next;
	while (pc && ++num_next < NUM_PRINT_PC)
		pc = pc->next;
	if (d->num_processes < NUM_PRINT_PC)
	{
		if (pos < num_prev || pos - num_prev > 0)
			return (num_prev);
	}
	else if (num_next + pos <= NUM_PRINT_PC && num_prev - (pos + num_next) > 0)
	{
		if (num_prev - pos < (NUM_PRINT_PC - num_next + pos))
			return (pos + (num_prev - pos));
		else
			return (pos + (NUM_PRINT_PC - (num_next + pos)));
	}
	return (pos);
}

void				print_pc_list(t_data *d)
{
	t_process	*pc;
	int			num_pc;

	d->vis.select_pos = calc_average(d, d->vis.select_pc, d->vis.select_pos);
	num_pc = d->vis.select_pos;
	pc = d->vis.select_pc;
	while (pc && num_pc >= 0)
	{
		print_pc_line(d->vis.win, pc, d->vis.select_pc, 39 + num_pc);
		pc = pc->prev;
		num_pc--;
	}
	num_pc = d->vis.select_pos;
	pc = d->vis.select_pc;
	while (pc && num_pc <= NUM_PRINT_PC)
	{
		print_pc_line(d->vis.win, pc, d->vis.select_pc, 39 + num_pc);
		pc = pc->next;
		num_pc++;
	}
	select_reg(d, d->vis.select_pc);
}
