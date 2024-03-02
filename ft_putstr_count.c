#include "libftprintf.h"

int ft_putstr_count(char *v, int fd)
{
	ft_putstr_fd(v, fd);
	return (ft_strlen(v));
}