#include <unistd.h>

int p_write(const char *s, const size_t len)
{
	write(1, s, len);
	return (len);
}