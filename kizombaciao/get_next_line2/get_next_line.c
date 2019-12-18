#include "get_next_line.h"
#include "./libft/libft.h"

static int	get_line_only(char **s, char **line)
{
	int l;
	char *tmp;

	l = 0;
	while ((*s)[l] != ENDL && (*s)[l] != '\0')
		l++;
	if ((*s)[l] == ENDL)
	{
		*line = ft_strsub(*s, 0, l);
		tmp = ft_strdup(&((*s)[l + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0') // edge case, how???
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && s[fd] == NULL)
		return (0);
	else
		return (get_line_only(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int r;
	char buf[BUFF_SIZE + 1];
	static char *s[FD_SIZE]; 
	char *tmp;

	if (fd < 0 || line == NULL)
		return (-1);

	//r = read(fd, buf, BUFF_SIZE);
	//buf[r] = '\0';
	//printf("\n%d  %d  %c  %c  %c  %s", fd, r, buf[0], buf[8], buf[9], buf);

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{	
		buf[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
			//s[fd] = ft_strnew(BUFF_SIZE);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], ENDL))
			break ;
	}
	return (output(s, line, r, fd));
}

/*
** basically, the program reads a string of length BUFF_SIZE and stores it into *s
** *s acts like a FIFO inventory,
** as soon as we see a '\n', we call get_line_only to chop off the line to return to main
** and what's leftover, we keep in *s, till we accumulate another '\n'
** 
** line == NULL because you can't access *line if line is NULL.
** variables declared in main will be in stack with a memory address.
** r = BUFF_SIZE, if there is sufficient text to read
** first time, s[fd] will be NULL
** s[fd] will add 15 chars (including the '\n') on top of previous chars
** 
** s[fd] is like an FIFO inventory
** and when s[fd] has a '\n', then we break and call output() and get_line_only()
** (*s)[l] = s[fd][l], given that *s = *(s + 0)
** *line = line[0], given that *line = *(line + 0)
** 
** 
** check: memory leak???
** 
** 
** 
** 
** 
** 
*/