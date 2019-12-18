#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define FD_SIZE	4096
# define BUFF_SIZE	15
# define ENDL		'\n'

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int get_next_line(const int fd, char **line);

#endif