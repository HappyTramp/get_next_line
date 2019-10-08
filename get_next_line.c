/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:37:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/08 15:35:43 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

/* static char	*split_newline(char *buf, char **line) */
/* { */
/* 	int split_index; */
/*  */
/* 	split_index = find_newline(buf); */
/* 	if (split_index != -1) */
/* 		buf[split_index] = '\0'; */
/* 	ft_strappend(*line, buf); */
/* 	if (split_index == -1) */
/* 		return (NULL); */
/* 	return (buf + split_index); */
/* } */

#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	int		slice_index;
	static char	buf[BUFFER_SIZE + 1] = "";

	/* *line = NULL; */
	if (buf[0] == '\0')
	{
		if (read(fd, buf, BUFFER_SIZE) == 0)
			return (NO_LINE_READ);
	}
	/* printf("%s\n", *line); */
	slice_index = find_newline(buf);
	if (slice_index == -1)
	{
		*line = strappend(*line, buf);
		buf[0] = '\0';
		return (get_next_line(fd, line));
	}
	buf[slice_index] = '\0';
	*line = strappend(*line, buf);
	ft_strcpy(buf, buf + slice_index + 1);
	return (LINE_READ);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("Makefile", O_RDONLY);
	char *line = NULL;
	int ret = 1;
	while (get_next_line(fd, &line) == 1)
	{
		printf("> %s\n", line);
		free(line);
		line = NULL;
	}
	/* free(line); */

	/* char c; */
	/* while (read(fd, &c, 1) > 0) */
	/* 	printf("%c", c); */
	/* while (read(fd, &c, 1) > 0) */
	/* 	printf("%c", c); */
	/* while (read(fd, &c, 1) > 0) */
	/* 	printf("%c", c); */
	close(fd);
	return 0;
}
