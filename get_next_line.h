/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:52:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/11 14:27:22 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define LINE_READ 1
# define END_OF_FILE 0
# define ERROR -1

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

/*
** get_next_line.c
*/

int		get_next_line(int fd, char **line);
char	*shift_rest(char *rest, int split_at);
int		find_newline(char *str);
t_bool	empty_rest(char *rest);

/*
** get_next_line_utils.c - helper functions
*/

char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strappend(char *dest, char *src);

#endif
