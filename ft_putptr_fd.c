#include "libftprintf.h"

static void conv_to_16(unsigned long n, char *base, int fd)
{
	if (n == 0)
		return;
	else
		conv_to_16(n/16, base, fd);
	ft_putchar_fd(base[n%16], fd);
}

int	ft_putptr_fd(void *p, int fd)
{
	unsigned long	n;
	char *base;

	if (!p)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	base = "0123456789abcdef";
	n = (unsigned long)p;
	ft_putstr_fd("0x", fd);
	conv_to_16(n, base, fd);
	return (14);
}
