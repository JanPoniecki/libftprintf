#include "libftprintf.h"

int	ft_printf(const char *src, ...)
{
	int	n;
	int	chars;
	va_list ap;

	n = count_args(src);
	printf("%d arguments found\n", n);
	va_start(ap, src);
	chars = print_stuff(src, ap);
	va_end(ap);
	return(chars);
}

