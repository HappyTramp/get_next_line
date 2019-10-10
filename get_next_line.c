/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:37:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/10 10:18:51 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

/*
** store rest in local_buf and read diff
** while no newline -> recursion
** newline -> store what is after newline
** 			  allocate line according to stack depth
** 			  cpy before newline at the end
** 			  at each stack pop store local buf on the allocated line
*/

#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	int			ret;
	int			split_at;
	char		local_buf[BUFFER_SIZE + 1];
	static int	line_len = 0;
	static char	rest_buf[BUFFER_SIZE + 1] = "";

	local_buf[0] = '\0';
	if ((ret = read_after(fd, local_buf, rest_buf)) <= 0)
		return (ret);
	if ((split_at = find_newline(local_buf)) != -1)
	{
		ft_strncpy(rest_buf, local_buf + split_at + 1,
					ft_strlen(local_buf) - split_at);
		if ((*line = malloc(sizeof(char) * (line_len + split_at + 1))) == NULL)
			return (ERROR);
		ft_strncpy(*line + line_len, local_buf, split_at);
		(*line)[line_len + split_at] = '\0';
		return (LINE_READ);
	}
	line_len += BUFFER_SIZE;
	if ((ret = get_next_line(fd, line)) == -1)
		return (ERROR);
	line_len -= BUFFER_SIZE;
	ft_strncpy(*line + line_len, local_buf, BUFFER_SIZE);
	return (ret);
}

int	read_after(int fd, char *buf, char *rest_buf)
{
	int	offset;
	int	ret;

	offset = ft_strlen(rest_buf);
	ft_strncpy(buf, rest_buf, offset);
	/* printf(">%s<\n", buf); */
	rest_buf[0] = '\0';
	if ((ret = read(fd, buf + offset, BUFFER_SIZE - offset)) == -1)
		return (ERROR);
	if (ret == 0)
		return (0);
	if (ret < BUFFER_SIZE - offset)
	{
		/* buf[offset + ret - 1] = '\0'; */
		/* printf(">eof? %s<\n", buf); */
	}
	else
		buf[BUFFER_SIZE] = '\0';
	return (ret);
}
