/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:27:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/10 11:04:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == LINE_READ)
	{
		printf("[%s]\n", line);
		free(line);
	}
	if (ret == -1)
		printf("error\n");
	else if (ret == 0)
		printf("EOF\n");
	close(fd);
	return (0);
}
