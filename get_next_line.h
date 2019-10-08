#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1 << 8)
# endif

# define LINE_READ 1
# define NO_LINE_READ 0
# define ERROR -1


/*
** get_next_line.c
*/

int		get_next_line(int fd, char **line);

/*
** get_next_line_utils.c - helper functions
*/

int		find_newline(char *str);
char	*strappend(char *dest, char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
int		ft_strlen(char *str);

#endif
