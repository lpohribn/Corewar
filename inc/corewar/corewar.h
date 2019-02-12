/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:27:19 by rnovodra          #+#    #+#             */
/*   Updated: 2018/11/16 10:27:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include "ft_printf.h"
# include "libft.h"
# include "op.h"
# include "visualization.h"
# include "network.h"

/*
** program size to execution code
*/

# define MAX_PLAYER_ID	UINT_MAX - NUM_OPERATION - MAX_PLAYERS
# define PROG_SIZE	(int)(sizeof(int) * 4 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define PC_POS(x)	(pc->pos + x) % MEM_SIZE

/*
** our player with some information about him
*/

typedef struct	s_player
{
	int				id;
	unsigned int	curr_period_live;
	unsigned int	last_live;
	char			prog_name[PROG_NAME_LENGTH];
	unsigned int	bot_size;
	char			comment[COMMENT_LENGTH];
	unsigned char	exec_code[CHAMP_MAX_SIZE];
}				t_player;

/*
** process
*/

typedef struct	s_process
{
	unsigned int		id;
	unsigned int		pos;
	_Bool				live;
	_Bool				carry;
	int					run_cycles;
	unsigned char		opcode;
	unsigned int		reg[REG_NUMBER];
	unsigned int		live_cycle;
	_Bool				error;
	short int			which_player;
	struct s_process	*next;
	struct s_process	*prev;
}				t_process;

/*
** all VM information
*/

typedef	struct	s_data
{
	t_player		player[MAX_PLAYERS];
	int				cur_cycle;
	int				cycle_to_die;
	short int		num_players;
	unsigned int	num_processes;
	unsigned char	memory[MEM_SIZE];
	int				num;
	int				octets;
	int				dump;
	_Bool			visual_mode;
	_Bool			leaks;
	_Bool			p_flag;
	_Bool			server;
	_Bool			help;
	_Bool			aff_print;
	int				info;
	int				execution_live;
	int				winner_id;
	t_process		*beg_pc;
	t_vis			vis;
	t_server		srv;
}				t_data;

void			usage(t_data *d, const char *prog_name);

/*
** argument handling functions
*/

int				handle_arguments(t_data *d, const int argc, char const *argv[]);
int				handle_option(t_data *d, const char *argv[]);
int				handle_file(t_data *d, const char *filename, _Bool check);
int				handle_champion(t_data *d, const char *champname);

/*
** process functions
*/

void			create_pc(t_data *d, t_process const *cpy,
				unsigned int const pos);
void			delete_pc(t_data *d, t_process **del);

/*
** corewar
*/

int				prepare_game(t_data *d);
void			dump_memory(t_data *d);
int				game(t_data *d);
int				get_arg(t_data *d, unsigned int pos, unsigned int const size);
int				get_arg_val(t_data *d, t_process *pc,
				unsigned char const arg, short int *offset);
int				hanlde_codage(unsigned char *arg,
				unsigned char const opcode, unsigned char const codage);
void			change_pc_pos(t_process *p, unsigned char const opcode,
				unsigned char *arg);
void			set_memory(t_process *const pc, t_data *d,
				int pos, int const value);
void			set_reg(t_process *p, const int reg, const int val);
short int		get_reg(t_data *d, t_process *p, short int *offset);
void			break_plives(t_data *d);

/*
** xerror output errors and call xexit with failure status
** xexit exiting and cleaning everything if needed
*/

void			xerror(t_data *d, const char *msg,
				const int status) __attribute__((noreturn));
void			xexit(t_data *d, const int status) __attribute__((noreturn));

/*
** operations
*/

void			live_op(t_data *d, t_process *const p);
void			arithmetic_op(t_data *d, t_process *const p);
void			bitwise_op(t_data *d, t_process *const p);
void			load_op(t_data *d, t_process *const p);
void			fork_op(t_data *d, t_process *const p);
void			loadindex_op(t_data *d, t_process *const p);
void			sti_op(t_data *d, t_process *const p);
void			st_op(t_data *d, t_process *const p);
void			zjmp_op(t_data *d, t_process *const p);
void			aff_op(t_data *d, t_process *const p);

/*
** enum operations
*/

enum	e_op
{
	undefined,
	live,
	ld,
	st,
	add,
	sub,
	and,
	or,
	xor,
	zjmp,
	ldi,
	sti,
	_fork,
	lld,
	lldi,
	lfork,
	aff
};

/*
** array of pointers to functions which are above
*/

extern void	(*const g_fnop[NUM_OPERATION])(t_data *d, t_process *const p);

#endif
