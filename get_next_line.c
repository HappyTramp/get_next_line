#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static unsigned int cursor;

/* static void *ft_memcat(void *ptr, void *tail, */
/*                         unsigned int size, unsigned int tail_size); */

int get_next_line(const int fd, char **line)
{
    /* unsigned int    newline_i; */
    /* char            buf[BUFF_SIZE]; */
    /*  */
    /* if (read(fd, buf, BUFF_SIZE) < 0) */
    /*     return (-1); */
    /* if ((*line = ft_strnew(0)) == NULL) */
    /*     return (-1); */
    /* newline_i = 0; */
    /* while (buf[newline_i]) */
    /* { */
    /*     while (buf[newline_i] != '\n') */
    /*         newline_i++; */
    /*     ft_memcat(*line, buf, 0, newline_i); */
    /*     if (read(fd, buf, BUFF_SIZE) < 0) */
    /*         return (-1); */
    /* } */
    return (0);
}
/*  */
/* static void *ft_memcat(void *ptr, void *tail, */
/*                         unsigned int size, unsigned int tail_size) */
/* { */
/*     void *copy; */
/*  */
/*     if ((copy = malloc(size)) == NULL) */
/*         return (NULL); */
/*     ft_memcpy(copy, ptr, size); */
/*     free(ptr); */
/*     if ((ptr = malloc(size + tail_size)) == NULL) */
/*         return (NULL); */
/*     ft_memcpy(ptr, copy, size); */
/*     free(copy); */
/*     ft_memcpy(ptr + size, tail, tail_size); */
/*     return (ptr); */
/* } */

int main()
{
	printf("test\n");
	return 0;
}
