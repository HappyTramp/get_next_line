#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
    char buf[BUFF_SIZE];

    while ((read(fd, buf, BUFF_SIZE)) > 0)
    {

    }
    return 0;
}
