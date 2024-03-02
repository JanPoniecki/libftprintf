#include "libftprintf.h"

int	ft_putnbr_count(int v, int fd)
{
	int	chars;

	ft_putnbr_fd(v, fd);
	chars = 0;
	if (v <= 0)
		chars ++;
	while (v != 0)
	{
		v = v/10;
		chars ++;
	}
	return (chars);
}