/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:23:21 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/02 14:23:25 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar_fd_count(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

static int	print_var_4(char s, int v)
{
	int	chars;

	chars = 0;
	if (s == 'd' || s == 'i')
		chars += ft_putnbr_count(v, 1);
	if (s == 'c')
		chars += ft_putchar_fd_count(v, 1);
	if (s == 'u')
		chars += ft_putud_fd((unsigned int)v, 1);
	if (s == 'x' || s == 'X')
		chars += ft_puthex_fd((unsigned int)v, 1, s);
	return (chars);
}

static int	print_var_8(char s, void *v)
{
	int	chars;

	chars = 0;
	if (s == 's')
		chars += ft_putstr_count((char *)v, 1);
	if (s == 'p')
		chars += ft_putptr_fd(v, 1);
	return (chars);
}

int	print_stuff(const char *s, va_list ap)
{
	int	mode;
	int	chars;

	mode = -1;
	chars = 0;
	while (*s)
	{
		if (*s == '%' && mode == -1)
			mode *= -1;
		else if (mode == 1)
		{
			if (*s == '%')
				chars += ft_putchar_fd_count(*s, 1);
			if (strchr("dicuxX", *s))
				chars += print_var_4(*s, va_arg(ap, int));
			if (strchr("sp", *s))
				chars += print_var_8(*s, va_arg(ap, void *));
			mode *= -1;
		}
		else
			chars += ft_putchar_fd_count(*s, 1);
		s++;
	}
	return (chars);
}
