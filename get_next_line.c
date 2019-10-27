/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:08:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/27 21:50:24 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"

/*
** if has rest:
**     if rest has newline:
**         push rest until newline in line, shift rest
**         return LINE_READ
**     else:
**         push rest in line
**
** while can read fd in buf
**     if buf has newline:
**         push buf until newline in line
**         push buf after newline in rest
**         return LINE_READ
**     push buf in line
**
** return GNL_EOF
*/

int		real_get_next_line(int fd, char **line, int ret, int counter)
{
	int			split_at;
	t_bool		had_rest;
	char		buf[BUFFER_SIZE + 1];
	static char	rest[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};

	if ((had_rest = put_rest(line, rest[fd])) == -1)
		return (LINE_READ);
	while (rest[fd][0] == '\0' && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		counter++;
		buf[ret] = '\0';
		if ((split_at = find_newline(buf)) != -1)
		{
			ft_strncpy(rest[fd], buf + split_at + 1, BUFFER_SIZE);
			buf[split_at] = '\0';
			*line = ft_strappend(*line, buf);
			return (*line == NULL ? ERROR : LINE_READ);
		}
		if ((*line = ft_strappend(*line, buf)) == NULL)
			return (ERROR);
	}
	if (ret == -1)
		return (clean_line(line, ERROR));
	return (had_rest || counter != 0 ? LINE_READ : clean_line(line, GNL_EOF));
}

int		get_next_line(int fd, char **line)
{
	int		ret;
	int		counter;

	ret = 0;
	counter = 0;
	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE < 0)
		return (ERROR);
	if (BUFFER_SIZE == 0)
	{
		*line = NULL;
		return (LINE_READ);
	}
	return (real_get_next_line(fd, line, ret, counter));
}

int		put_rest(char **line, char *rest)
{
	int		split_at;
	t_bool	had_rest;

	had_rest = rest[0] != '\0';
	if ((split_at = find_newline(rest)) == -1)
	{
		*line = malloc(sizeof(char) * (ft_strlen(rest) + 1));
		ft_strcpy(*line, rest);
		rest[0] = '\0';
		return (had_rest);
	}
	if (split_at + 1 == ft_strlen(rest))
		had_rest = -1;
	*line = malloc(sizeof(char) * (split_at + 1));
	ft_strncpy(*line, rest, split_at);
	(*line)[split_at] = '\0';
	ft_strncpy(rest, rest + split_at + 1, BUFFER_SIZE);
	return (had_rest);
}

int		find_newline(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int		clean_line(char **line, int ret)
{
	free(*line);
	*line = NULL;
	return (ret);
}
