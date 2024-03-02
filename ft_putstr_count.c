#include "libftprintf.h"

int ft_putstr_count(char *v, int fd)
{
	if (!v)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(v, fd);
	return (ft_strlen(v));
}