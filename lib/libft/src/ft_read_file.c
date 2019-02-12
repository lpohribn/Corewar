/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:37:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/07 12:37:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*file;
	char	*tmp;
	int		ret;

	if (read(fd, buff, 0) < 0 || !(file = ft_strnew(1)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		tmp = file;
		file = ft_strjoin(file, buff);
		free(tmp);
		if (!file)
			return (NULL);
	}
	if (ret < 0)
	{
		free(file);
		return (0);
	}
	return (file);
}
