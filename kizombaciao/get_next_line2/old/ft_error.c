#include "get_next_line.h"
#include "../libft/libft.h"

int     ft_open_error(int fd)
{
    if (fd == -1)
    {
        ft_putstr("open() failed.\n");
		return (0);
    }
    return (1);
}

int     ft_close_error(int fd)
{
    if (fd == -1)
    {
        ft_putstr("close() failed.\n");
		return (0);
    }
    return (1);
}
