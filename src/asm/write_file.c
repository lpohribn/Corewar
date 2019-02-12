/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:16:45 by opletsan          #+#    #+#             */
/*   Updated: 2018/11/14 17:16:47 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	write_coms_and_args(t_command *c, int fd)
{
	int		i;

	while (c && c->name)
	{
		write(fd, &c->opcode, 1);
		if (c->f_codage)
			write(fd, &c->codage, 1);
		i = -1;
		while (c->a[++i].type)
		{
			if (c->a[i].type == T_REG)
				write(fd, &c->a[i].value, T_REG);
			else if (c->a[i].type == T_DIR)
				write(fd, &c->a[i].value,
						DIR_SIZE >> g_op_tab[c->opcode].label);
			else if (c->a[i].type == T_IND)
				write(fd, &c->a[i].value, IND_SIZE);
		}
		c = c->next;
	}
	close(fd);
}

void				write_file(t_data *d)
{
	t_command		*c;
	unsigned int	magic;
	int				fd;

	if ((fd = open(d->file_name, O_CREAT | O_TRUNC | O_RDWR, 0777)) < 0)
	{
		d->error = -1;
		return ;
	}
	c = d->c;
	ft_printf("Writing output program to %s\n", d->file_name);
	if (g_flag)
	{
		print_bot(d, d->l, d->c);
		g_flag = 0;
	}
	magic = reverse_bytes(COREWAR_EXEC_MAGIC, 4);
	d->prog_size = reverse_bytes(d->prog_size, 4);
	ft_strcpy(d->prog_name, d->name);
	ft_strcpy(d->prog_comment, d->comment);
	write(fd, &magic, 4);
	write(fd, d->prog_name, PROG_NAME_LENGTH + 4);
	write(fd, &d->prog_size, 4);
	write(fd, d->prog_comment, COMMENT_LENGTH + 4);
	write_coms_and_args(d->c, fd);
}
