/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:52:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/10 10:19:54 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (15)
# endif

# define LINE_READ 1
# define END_OF_FILE 0
# define ERROR -1

/*
** get_next_line.c
*/

int		get_next_line(int fd, char **line);
int		read_after(int fd, char *buf, char *rest_buf);

/*
** get_next_line_utils.c - helper functions
*/

int		find_newline(char *str);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strlen(char *str);

#endif
