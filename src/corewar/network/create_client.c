/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:32:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/12/19 20:32:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	validate_name(const char *name)
{
	int	i;
	int	ch;

	i = 0;
	while (name[i + 1])
	{
		if (ft_isprint(name[i]) == 0 || ft_isascii(name[i]) == 0)
		{
			ft_printf("Name has invalid characters {%c}\n", name[i]);
			return (-1);
		}
		++i;
	}
	if (name[i] != '\n')
	{
		ft_printf("The name is too big(name > %d)\n", NAME);
		while ((ch = fgetc(stdin)) != '\n' && ch != EOF)
			;
	}
	else if (i > 2)
		return (0);
	else
		ft_printf("The name is too small(name < 3)\n");
	return (-1);
}

static inline int	get_client_name(t_token *t)
{
	char	name[NAME + 2];

	ft_putstr("\033[2J\033[1;1H");
	while (1)
	{
		ft_putstr("Print your name : ");
		if (fgets(name, sizeof(name), stdin) == NULL)
			return (1);
		if (ft_strcmp(name, "\n") == 0)
			ft_printf("Enter the name or \"quit\" to exit from program\n");
		else if (ft_strcmp(name, "quit\n") == 0)
			return (1);
		else if (validate_name(name) == 0)
			break ;
	}
	name[ft_strlen(name) - 1] = '\0';
	ft_strncpy((char*)t->data, name, NAME);
	return (0);
}

inline static int	who_is_client(t_data *d, const char *argv[],
					t_token *t)
{
	if (argv[1])
	{
		if (handle_file(d, argv[1], 1) < 0)
			return (-1);
		ft_strncpy(t->type, "player", ft_strlen("player"));
		ft_memcpy((t->data + NAME + 1), d->player, sizeof(t_player));
	}
	else
		ft_strncpy(t->type, "viewer", ft_strlen("viewer"));
	if (get_client_name(t) > 0)
		xexit(d, EXIT_SUCCESS);
	return (0);
}

int					create_client(t_data *d, t_network *net,
					const char *argv[])
{
	t_token		t;

	if (argv[0] == NULL || is_valid_ip(argv[0]) <= 0)
	{
		ft_dprintf(STDERR_FILENO, "corewar: incorrect IP of server\n");
		return (-1);
	}
	if (who_is_client(d, argv, &t) < 0)
		return (-1);
	if (connect_request(&net->sockfd, &net->addr, argv[0]) < 0)
		xerror(d, NULL, 1);
	if (connect(net->sockfd, (struct sockaddr *)&net->addr,
		sizeof(struct sockaddr)) == -1)
		xerror(d, NULL, 1);
	if (send_token(d, net->sockfd, &t) == 0)
		xerror(d, NULL, 10);
	return (0);
}
