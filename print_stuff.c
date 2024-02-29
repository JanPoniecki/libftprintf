#include "libftprintf.h"

static void	print_var_4(char s, int v)
{
	if (s == 'd' || s == 'i')
		ft_putnbr_fd(v, 1);
	if (s == 'c')
		ft_putchar_fd(v, 1);
}

static void	print_var_8(char s, void *v)
{
	if (s == 's')
		ft_putstr_fd((char *)v, 1);
}

int	print_stuff(const char *s, va_list ap)
{
	int		mode;

	mode = -1;
	while (*s)
	{
		if (*s == '%' && mode == -1)
			mode *= -1;
		else if (mode == 1)
		{
			if (strchr("dic", *s))
				print_var_4(*s, va_arg(ap, int));
			if (strchr("s", *s))
				print_var_8(*s, va_arg(ap, void *));
			mode *= -1;
		}
		else
			ft_putchar_fd(*s, 1);
		s++;
	}
	return (0);
}
