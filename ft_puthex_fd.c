#include "libftprintf.h"

static void conv_to_16(unsigned int n, char *base, int fd, int *chars)
{
	if (n == 0)
		return;
	else
	{
		(*chars)++;
		conv_to_16(n/16, base, fd, chars);
	}
	ft_putchar_fd(base[n%16], fd);
}

int	ft_puthex_fd(unsigned int n, int fd, char cse)
{
	int	chars;

	chars = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	char *base;

	if (cse == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	conv_to_16(n, base, fd, &chars);
	return (chars);
}
