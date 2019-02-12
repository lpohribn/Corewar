/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isproc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:03:17 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/11 15:03:18 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>

static inline int	ft_writesysinfo(const char *proc_name)
{
	const size_t	lpn = ft_strlen(proc_name);
	char			*str;

	if (!(str = ft_strnew(6 + lpn + 17)))
		return (-1);
	ft_strcpy(str, "pgrep ");
	ft_strcat(str, proc_name);
	ft_strcat(str, " > ./isproc_cache");
	if (system(str) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

static inline int	ft_readsysinfo(char *buff, const char *proc_name)
{
	int		fd;
	int		ret;

	if ((fd = open("./isproc_cache", O_CREAT | O_RDWR, 0666)) < 0)
		return (-1);
	if (ft_writesysinfo(proc_name) < 0)
	{
		remove("./isproc_cache");
		close(fd);
		return (-1);
	}
	if ((ret = read(fd, buff, 32)) < 0)
		return (-1);
	buff[ret] = 0;
	if (remove("./isproc_cache") < 0 || close(fd) < 0)
		return (-1);
	return (0);
}

int					ft_isproc(const char *proc_name)
{
	char	buff[32];
	int		ret;
	int		nbr;

	if (!proc_name)
		return (-1);
	if (ft_readsysinfo(buff, proc_name) < 0)
		return (-1);
	if ((nbr = ft_atoi(buff)) <= 0)
		return (0);
	ret = getpgid(nbr);
	if (ret == -1 && errno == ESRCH)
		return (0);
	return (1);
}
