/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:08:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/20 08:29:44 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
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
** return END_OF_FILE
*/

int		get_next_line(int fd, char **line)
{
	t_bool		had_rest;
	int			ret;
	int			split_at;
	char		buf[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || line == NULL)
		return (ERROR);
	if ((had_rest = put_rest(line, rest)) == -1)
		return (LINE_READ);
	while (rest[0] == '\0' && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((split_at = find_newline(buf)) != -1)
		{
			ft_strncpy(rest, buf + split_at + 1, BUFFER_SIZE);
			buf[split_at] = '\0';
			*line = ft_strappend(*line, buf);
			return (*line == NULL ? ERROR : LINE_READ);
		}
		if ((*line = ft_strappend(*line, buf)) == NULL)
			return (ERROR);
	}
	if (had_rest)
		return (LINE_READ);
	return (ret == -1 ? ERROR : END_OF_FILE);
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
