/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:51:06 by lpohribn          #+#    #+#             */
/*   Updated: 2018/11/19 15:51:09 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H

# include <curses.h>

# define L1 L"██████╗  ██████╗  ██████╗  ███████╗ ██╗    ██╗  █████╗  ██████╗  "
# define L2 L"██╔════╝ ██╔═══██╗ ██╔══██╗ ██╔════╝ ██║    ██║ ██╔══██╗ ██╔══██╗"
# define L3 L"██║      ██║   ██║ ██████╔╝ █████╗   ██║ █╗ ██║ ███████║ ██████╔╝"
# define L4 L"██║      ██║   ██║ ██╔══██╗ ██╔══╝   ██║███╗██║ ██╔══██║ ██╔══██╗"
# define L5 L"╚██████╗ ╚██████╔╝ ██║  ██║ ███████╗ ╚███╔███╔╝ ██║  ██║ ██║  ██║"
# define L6 L" ╚═════╝  ╚═════╝  ╚═╝  ╚═╝ ╚══════╝  ╚══╝╚══╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝"
# define L7 L"                               © rnovodra lpohribn opletsan, 2018"

# define L8 L"  ▓██▄ ▄██░"
# define L9 L" ▓█████████░"
# define L10 L"  ▓███████▒"
# define L11 L"  ░▒████▒░"
# define L12 L"    ░▐█░ "

# define S1 L"    ▄▄▄▄▄▄"
# define S2 L"  ▄▀██▀▀███"
# define S3 L"  ▐ ▐█░ ▐██░"
# define S4 L"  ░█▄▄███▒░"
# define S5 L"   ░███ ░░"
# define S6 L"  ░ ░    ░"

# define C1 L"  ▄ ▄▄▄▄▄▄ ▄▄"
# define C2 L" ▐▐█░   ▄ █ █"
# define C3 L"  ▀██░█████░"
# define C4 L"    ▀▀██▀ ░░"
# define C5 L"      ▐▄░"
# define C6 L"     ▄██▄░ "

# define RED_BLACK		1
# define VIOL_BLACK		2
# define GREEN_BLACK	3
# define CYAN_BLACK		4
# define GREY_BLACK		5
# define BLACK_RED		6
# define BLACK_VIOL		7
# define BLACK_GREEN	8
# define BLACK_CYAN		9
# define GREY_GREY		10
# define WHITE_RED		11
# define WHITE_VIOL		12
# define WHITE_GREEN	13
# define WHITE_CYAN		14
# define WHITE_GREY		15
# define WHITE_BLACK	16
# define BLACK_ORANGE	17
# define ORANGE_BLACK	18
# define BLACK_GREY		19

# define WIN_WIDTH		272
# define WIN_HEIGHT		76

# define KEY_SPACE		32
# define KEY_ESC		27
# define KEY_MINUS		45
# define KEY_PLUS		61
# define KEY_SHIFT_PL	43
# define KEY_SHIFT_MIN	95
# define KEY_RETURN		10
# define KEY_TAB		9

# define WIN_WCENTR		WIN_WIDTH / 2
# define WIN_HCENTR		WIN_HEIGHT / 2
# define SPEED			(unsigned long)(CLOCKS_PER_SEC / d->vis->speed)
# define NUM_PRINT_PC	15

# define NAME_SIZE		30

# define DEFAULT_SPEED	60
# define MIN_SPEED		1
# define MAX_SPEED		1000
# define HEIGHT			MEM_SIZE / 62
# define WIDTH			MEM_SIZE / 21

typedef struct s_data	t_data;
typedef struct s_process	t_process;
typedef struct s_player	t_player;

typedef	struct	s_cell
{
	short int	color;
	short int	live_times;
	short int	fl_light;
	_Bool		process;
}				t_cell;

typedef	struct	s_vis
{
	WINDOW		*win;
	t_cell		cell[MEM_SIZE];
	int			speed;
	short		select_pos;
	short		prev_color;
	t_process	*select_pc;
	_Bool		pause;
	_Bool		isinit;
	_Bool		one_step;
}				t_vis;

void			init_ncurses(t_data *d);
int				visualization(t_data *d);
void			print_title(WINDOW *win);
void			print_hearts(t_data *d);
void			record_pc(t_data *d);
void			print_pause(WINDOW *win, _Bool pause);
void			print_players(WINDOW *win, t_player *p, const int num_player);
void			print_info_sidebar(t_data *d, WINDOW *win);
void			print_window(WINDOW *win);
void			print_game(t_data *d);
void			print_memory(WINDOW *win, unsigned char *memory,
				t_cell *cell, _Bool pause);
void			init_register(t_data *d);
void			print_winner(t_data *d);
void			key_events(t_data *d);
void			record_live(t_data *d);
void			print_pc_list(t_data *d);
void			print_controls(WINDOW *win);
void			prepare_visual(t_data *d);

/*
** function is calling only if server turn on
*/

void			print_connections(t_data *d);

#endif
