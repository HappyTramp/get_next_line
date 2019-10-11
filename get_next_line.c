/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:37:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/11 14:29:11 by cacharle         ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	int			ret;
	int			split_at;
	char		buf[BUFFER_SIZE + 1];
	static char	*rest = NULL;

	if (fd < 0 || line == NULL)
		return (ERROR);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || !empty_rest(rest))
	{
		buf[ret] = 0;
		rest = ft_strappend(rest, buf);
		if ((split_at = find_newline(rest)) == -1 && ret == 0)
			split_at = ft_strlen(rest);
		if (split_at == -1)
			continue ;
		if ((*line = (char*)malloc(sizeof(char) * (split_at + 1))) == NULL)
			return (ERROR);
		ft_strncpy(*line, rest, split_at);
		(*line)[split_at] = '\0';
		return ((rest = shift_rest(rest, split_at)) == NULL
					? ERROR : LINE_READ);
	}
	free(rest);
	rest = NULL;
	return (ret == -1 ? ERROR : END_OF_FILE);
}

char	*shift_rest(char *rest, int split_at)
{
	char	*copy;
	int		len;

	len = ft_strlen(rest) - split_at + 1;
	if ((copy = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_strncpy(copy, rest + split_at + 1, len);
	free(rest);
	if ((rest = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_strncpy(rest, copy, len);
	free(copy);
	return (rest);
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

t_bool	empty_rest(char *rest)
{
	if (rest == NULL)
		return (TRUE);
	if (rest[0] == 0)
		return (TRUE);
	return (FALSE);
}
