/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:08:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/03 00:33:16 by cacharle         ###   ########.fr       */
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

#define HAS_NEWLINE(str, split_at)    ((split_at = find_newline(str)) != -1)
#define HAS_NO_NEWLINE(str, split_at) ((split_at = find_newline(str)) == -1)

int		get_next_line(int fd, char **line)
{
	int			split_at;
	static char	*rest[OPEN_MAX] = {NULL};

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (STATUS_ERROR);
	*line = NULL;
	if (rest[fd] == NULL || rest[fd][0] == 0)
		return (read_line(fd, line, &rest[fd]));
	if (HAS_NEWLINE(rest[fd], split_at))
	{
		if ((*line = (char*)malloc(sizeof(char) * (split_at + 1))) == NULL)
			return (STATUS_ERROR);
		ft_strncpy(*line, rest[fd], split_at);
		(*line)[split_at] = '\0';
		ft_strcpy(rest[fd], rest[fd] + split_at + 1);
		return (STATUS_LINE);
	}
	if (!(*line = (char*)malloc(sizeof(char) * (ft_strlen(rest[fd]) + 1))))
		return (STATUS_ERROR);
	ft_strcpy(*line, rest[fd]);
	free(rest[fd]);
	rest[fd] = NULL;
	return (read_line(fd, line, &rest[fd]));
}

int		read_line(int fd, char **line, char **rest)
{
	int		ret;
	int		split_at;
	char	*buf;

	if ((buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (STATUS_ERROR);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (HAS_NEWLINE(buf, split_at))
		{
			free(*rest);
			*rest = ft_strdup(buf + split_at + 1);
			buf[split_at] = '\0';
			if ((*line = ft_strappend(*line, buf)) == NULL)
				return (free_return(&buf, rest, STATUS_ERROR));
			return (free_return(&buf, NULL, STATUS_LINE));
		}
		if ((*line = ft_strappend(*line, buf)) == NULL)
			return (free_return(&buf, rest, STATUS_ERROR));
	}
	return (free_return(&buf, rest, ret));
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

int		free_return(char **ptr, char **ptr2, int ret)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (ret);
}
