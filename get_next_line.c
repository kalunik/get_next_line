/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjonatho <wjonatho@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:08:02 by wjonatho          #+#    #+#             */
/*   Updated: 2021/10/02 17:08:02 by wjonatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_rest_exists(char **rest, char *buf)
{
	char		*tmp;

	if (*rest)
	{
		tmp = *rest;
		*rest = ft_strjoin(*rest, buf);
		free(tmp);
		free(buf);
	}
	else
	{
		*rest = ft_strdup(buf);
		free(buf);
	}
}

void	ft_rest(char **rest, char **line)
{
	char	*ptr;
	char	*tmp;

	if (*rest)
	{
		ptr = ft_strchr(*rest, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strdup(*rest);
			tmp = *rest;
			*rest = ft_strdup(++ptr);
			free(tmp);
		}
	}
}

void	last_line(char **rest, char **line)
{
	if (*rest)
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
}

int	gnl_operations(char **rest, char **buf, char **line, ssize_t r)
{
	ft_rest_exists(rest, *buf);
	if (ft_strchr(*rest, '\n'))
	{
		ft_rest(rest, line);
		return (1);
	}
	if (!(ft_strchr(*rest, '\n')) && r == 0)
	{
		last_line(rest, line);
		return (0);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest;
	ssize_t		r;
	char		*buf;
	int			bool;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || line == 0)
		return (-1);
	r = 1;
	while (r > 0)
	{
		buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (buf == NULL)
			return (-1);
		r = read(fd, buf, BUFFER_SIZE);
		bool = gnl_operations(&rest, &buf, line, r);
		if (bool > -1)
			return (bool);
	}
	return (0);
}
