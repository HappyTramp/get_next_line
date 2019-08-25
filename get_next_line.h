#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define NEWLINE 0x0A
# define BUFF_SIZE (1 << 8)

int get_next_line(const int fd, char **line);

#endif
