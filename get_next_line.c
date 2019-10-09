/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:37:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/09 16:50:40 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

// if has rest
//      store it in local_buf and read diff
// else
// 		read full local buf
// while no newline -> recursion
// newline -> store what is after newline
// 			  allocate line according to stack depth
// 			  cpy before newline at the end
// 			  at each stack pop store local buf on the allocated line


int read_after(int fd, char *buf, char *rest_buf)
{
	int offset = ft_strlen(rest_buf);
	ft_strncpy(buf, rest_buf, offset);
	rest_buf[0] = 0;
	return (read(fd, buf + offset, BUFFER_SIZE - offset));
}

int	get_next_line(int fd, char **line)
{
	int		split_at;
	char 	local_buf[BUFFER_SIZE + 1];
	static int buf_count = 0;
	static char	rest_buf[BUFFER_SIZE + 1] = "";

	local_buf[0] = '\0';
	if (read_after(fd, local_buf, rest_buf) == 0)
		return (END_OF_FILE);
	split_at = find_newline(local_buf);
	if (split_at == -1)
	{
		buf_count++;
		int ret = get_next_line(fd, line);
		buf_count--;
		ft_strncpy(*line + (buf_count * BUFFER_SIZE), local_buf, BUFFER_SIZE);
		return (ret);
	}
	ft_strncpy(rest_buf, local_buf + split_at + 1, ft_strlen(local_buf) - split_at);
	*line = malloc(sizeof(char) * (buf_count * BUFFER_SIZE + split_at + 1));
	ft_strncpy(*line + (buf_count * BUFFER_SIZE), local_buf, split_at);
	(*line)[buf_count * BUFFER_SIZE + split_at] = '\0';
	return (LINE_READ);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("Makefile", O_RDONLY);
	char *line = NULL;
	/* int ret = 1; */
	while (get_next_line(fd, &line) == 1)
	{
		printf(">%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
