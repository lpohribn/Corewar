/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:20:10 by opletsan          #+#    #+#             */
/*   Updated: 2018/11/06 17:20:12 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include <errno.h>

typedef struct			s_arg
{
	char				*str_value;
	unsigned int		value;
	char				type;
}						t_arg;

typedef struct			s_command
{
	char				*line;
	unsigned int		byte;
	char				*name;
	short int			opcode;
	_Bool				f_codage;
	_Bool				f_label;
	unsigned char		codage;
	t_arg				a[MAX_ARGS_NUMBER];
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char				*name;
	unsigned int		address;
	struct s_label		*next;
}						t_label;

typedef struct			s_data
{
	char				prog_name[PROG_NAME_LENGTH + 4];
	char				prog_comment[COMMENT_LENGTH + 4];
	char				*name;
	unsigned int		prog_size;
	char				*comment;
	char				*file_name;
	int					fd;
	int					num_line;
	int					num_col;
	int					error;
	char				*error_str;
	char				f;
	_Bool				flag;
	_Bool				no_str;
	t_command			*c;
	t_label				*l;
}						t_data;

_Bool					g_flag;

void					parcel_line(t_data *d, char *line);
unsigned int			reverse_bytes(unsigned int x, int bytes);
void					write_file(t_data *d);
void					ft_error(t_data *d, char *arg);
void					get_name_or_comment(t_data *d, char *s);
void					get_label(t_data *d, char *s, int st, int fn);
t_command				*get_command(t_data *d, char *s, int st, int end);
int						get_arguments(t_data *d, t_command *c, char *s, int st);
char					get_type(char *str);
void					save_data(t_data *d, t_command *c);
void					final_valid(t_data *d, int ret);
void					print_bot(t_data *d, t_label *l, t_command *c);

#endif
