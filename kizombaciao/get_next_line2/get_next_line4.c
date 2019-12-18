
#include "get_next_line.h"
#include "./libft/libft.h"

static int glo(char **s, char **line)
{

	l = 0;
	while ((*s)[l]) != ENDL && (*s)[l] != '\0')
		l++;
	if ((*s)[l] == ENDL)
	{
		// COPY UP TO LEN CHAR STARTING FROM s[0] to malloc memory
		*line = ft_strsub(*s, 0, l);
		// put into tmp all remaining chars after '\n'
		tmp = ft_strdup(&((*s)[l + 1]));		
		free(*s); // free s[fd]
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
			// free if only '\0' in the leftover string
	}
	else
	{
		// if (*s)[l] == '\0', means we are at the end of the file
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int out(char **s, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && s[fd] == NULL)
		return (0);
	else
		return (glo(&s[fd], line));	
}

int	gnl(const int fd, char **line)
{
	int r;
	char buf[BUFF_SIZE + 1];
	static char *s[FD_SIZE];
	char *tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0'; // end each string read with a '\0'
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf); // copy string to new malloc memory
		else
		{
			// otherwise, append buffer to end of string
			tmp = ft_strjoin(s[fd], buf); // creates new malloc memory
			free(s[fd]); // free old s[fd]
			s[fd] = tmp;
		}
		// if '\n' exists in the string
		if (ft_strchr(s[fd], ENDL))
			break;
	}
	return (out(s, line, r, fd));
}

// We consider also that a call to lseek(2) will never take place 
// between two calls of the function get_next_line on the same file descriptor.

