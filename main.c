/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:27:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/02 22:42:58 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
	{
		printf("You forgot the filename");
		exit(1);
	}
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &line)) == STATUS_LINE)
	{
		printf("%3d [%s]\n", ++i, line);
		free(line);
	}
	if (ret == -1)
		printf("error\n");
	else if (ret == 0)
		printf("EOF\n");
	close(fd);
	return (0);
}
