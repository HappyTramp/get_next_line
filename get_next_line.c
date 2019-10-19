/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:08:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/19 16:19:25 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			ret;
	int			split_at;
	char		buf[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || line == NULL)
		return (ERROR);
	int has_stuff = rest[0] != 0;
	*line = put_rest(*line, rest);
	if (rest[0] != '\0')
		return (LINE_READ);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)// || rest[0] != '\0')
	{
		buf[ret] = '\0';
		split_at = find_newline(buf);
		if (split_at == -1)
		{
			*line = ft_strappend(*line, buf);
			continue ;
		}
		buf[split_at] = '\0';
		ft_strncpy(rest, buf + split_at + 1, BUFFER_SIZE + 1);
		*line = ft_strappend(*line, buf);
		return LINE_READ;
	}
	if (has_stuff)
		return (LINE_READ);
	return (ret == -1 ? ERROR : END_OF_FILE);
}

char	*put_rest(char *line, char *rest)
{
	int	split_at;

	split_at = find_newline(rest);
	if (split_at == -1)
	{
		line = malloc(sizeof(char) * (ft_strlen(rest) + 1));
		ft_strcpy(line, rest);
		/* line[ft_strlen(rest)] = 0; */
		rest[0] = '\0';
		return (line);
	}
	line = malloc(sizeof(char) * (split_at + 1));
	ft_strncpy(line, rest, split_at + 1);
	line[split_at] = '\0';
	ft_strncpy(rest, rest + split_at + 1, BUFFER_SIZE);
	return (line);
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
