/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 04:14:26 by opletsan          #+#    #+#             */
/*   Updated: 2019/01/13 04:14:28 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	ft_error2(int error)
{
	if (error == 11)
		ft_putstr_fd("Label already exists", STDERR_FILENO);
	else if (error == 12)
		ft_putstr_fd("Invalid command", STDERR_FILENO);
	else if (error == 13)
		ft_putstr_fd("Invalid argument", STDERR_FILENO);
	else if (error == 14)
		ft_putstr_fd("Invalid number of arguments", STDERR_FILENO);
	else if (error == 15)
		ft_putstr_fd("No arguments", STDERR_FILENO);
	else if (error == 16)
		ft_putstr_fd("Too much separator chars", STDERR_FILENO);
	else if (error == 17)
		ft_putstr_fd("No such label", STDERR_FILENO);
	else if (error == 18)
		ft_putstr_fd("Invalid end of file", STDERR_FILENO);
	else if (error == 19)
		ft_putstr_fd("Empty file", STDERR_FILENO);
}

static inline void	ft_error1(int error)
{
	if (error == -1)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("Invalid file type", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("Invalid program name", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Invalid comment", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("No program name", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("No comment", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("Duplicate of the field .name", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("Duplicate of the field .comment", STDERR_FILENO);
	else if (error == 8)
		ft_putstr_fd("Too long name", STDERR_FILENO);
	else if (error == 9)
		ft_putstr_fd("Too long comment", STDERR_FILENO);
	else if (error == 10)
		ft_putstr_fd("Syntax error or undefined symbol", STDERR_FILENO);
	else
		ft_error2(error);
}

void				ft_error(t_data *d, char *arg)
{
	int		shft;
	int		i;

	i = -1;
	if (!d->error)
		return ;
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": \033[31m", STDERR_FILENO);
	ft_error1(d->error);
	ft_putendl_fd("\033[0m", STDERR_FILENO);
	if (d->error >= 2 && d->error <= 17)
	{
		ft_dprintf(STDERR_FILENO, "[%d:%d]: ", d->num_line, d->num_col);
		write(STDERR_FILENO, "\"", 1);
		while (d->error_str[++i])
		{
			if (d->error_str[i] == '\t')
				write(STDERR_FILENO, " ", 1);
			else
				write(STDERR_FILENO, &d->error_str[i], 1);
		}
		ft_putendl_fd("\"", STDERR_FILENO);
		shft = ft_numlen(d->num_line) + ft_numlen(d->num_col) + 6 + d->num_col;
		ft_dprintf(STDERR_FILENO, "\033[1;92m%*c\n\033[0m", shft, '^');
	}
}
