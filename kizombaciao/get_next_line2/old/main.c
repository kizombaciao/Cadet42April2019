#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int fd;
    char *line;

    fd = open(av[1], O_RDONLY);
	//if (!ft_open_error(fd))
	//	return (0);
    //printf("\n111  %d", fd);

    while (get_next_line(fd, &line) == 1) // **ptr necessary here???
        printf("\n%s", line);

	//if (!ft_close_error(close(fd)))
	//	return (0);
    close(fd);
	return (0);
}


// questions:
// page 5:  what is FORBIDDEN???
// what if the file has multiple '\n'???

// **s is necessary because it needs a 2-D array

// https://www.geeksforgeeks.org/static-variables-in-c/
// https://www.geeksforgeeks.org/memory-layout-of-c-program/
// https://www.tutorialspoint.com/cprogramming/c_constants.htm
