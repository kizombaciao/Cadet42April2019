#include "get_next_line.h"
#include "./libft/libft.h"

static int	append(char **s, char **line)
{
	int l;
	char *tmp;

	printf("\n444a %s", *s);
	printf("\n444b %s\n", *line);
	l = 0;
	// (*s) = s[fd]
	while ((*s)[l] != ENDL && (*s)[l] != '\0')
		l++;
	// (*s)[l] = s[fd][l]
	if ((*s)[l] == ENDL)
	{
		// copies from start index = 0 of string s to malloc allocated pointer.
		*line = ft_strsub(*s, 0, l); // *line = line[0] = *(line + 0)
		tmp = ft_strdup(&((*s)[l + 1])); // way to remove char after '\n'
		free(*s);
		*s = tmp; // tmp is shorter than original s
		// s contains what's left over after chopping off the front portion going to line.
		if ((*s)[0] == '\0') // edge case, how???
			ft_strdel(s); // why not free()???
	}
	// the case we don't have leftover to keep within FIFO inventory of s[fd]
	else // if (*s)[l] == '\0'
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	printf("\n4441a %s", *s);
	printf("\n4441b %s\n", *line);
	return (1);
}
// *s = s[0], which means (*s)[l + 1] = s[0][l + 1]
// but s[0] may be s[fd] in this case.
// is address of &s[1] same as &(*(s + 1)) same as &(*(*(s + 1) + 0))

static int	output(char **s, char **line, int r, int fd)
{
	//printf("\n333r:  %d\n", r);
	if (r < 0)
		return (-1);
	else if (r == 0 && s[fd] == NULL)
		return (0);
	else
	{
		return (append(&s[fd], line));
	}
}

int	get_next_line(const int fd, char **line)
{
	int r;
	char buf[BUFF_SIZE + 1];
	static char *s[FD_SIZE]; 
	char *tmp;

	//printf("\n222:  %s", s[fd]);
	//printf("\n222b:  %s", *line);
	// really need to check for line == NULL ?
	// because you can't assign string to *line if line is NULL.
	if (fd < 0 || line == NULL) // why would LINE not equal null in the beginnig ???
	{
		printf("\nHEY LINE!");
		return (-1);
	}
//	r = read(fd, buf, BUF_SIZE);
//	buf[r] = '\0';
//	printf("\n%d  %d  %c  %c  %c  %s", fd, r, buf[0], buf[8], buf[9], buf);
	// buf[10] = '\n'

	// DISCARD ENDL ? addressed later in append()
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{	
		buf[r] = '\0';
		if (s[fd] == NULL)
		{
			s[fd] = ft_strdup(buf);  // strnew.c ???
			//printf("\n222a %d %d %s", fd, r, s[fd]);
		}
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], ENDL)) // if there's a '\n' in the string
		{
			//printf("\n222c HEY!  %s\n", s[fd]);
			break ;
		}
	}
	printf("\n222e  %s\n", s[fd]);
	return (output(s, line, r, fd));
}
