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

#include "ft_printf.h"

/* static void	putchar_check(const char *s, int fd, int *chars)
{
	if (*s == '%' && *(s + 1) == 0)
	{
		*chars = -1;
		return ;
	}
	ft_putchar_fd(*s, fd);
	if (1 == 1)
		(*chars)++;
}

static int	print_var_4(char s, int v)
{
	int	chars;

	chars = 0;
	if (s == 'd' || s == 'i')
		y
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

int	check_char(char s, int fd)
{
	int	chars;

	chars = 0;
	chars += ft_putchar_fd_count('%', fd);
	if (s != '%')
		chars += ft_putchar_fd_count(s, fd);
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
		if (*s == '%' && mode == -1 && *(s + 1) != 0)
			mode *= -1;
		else if (mode == 1)
		{
			if (strchr("dicuxX", *s))
				chars += print_var_4(*s, va_arg(ap, int));
			else if (strchr("sp", *s))
				chars += print_var_8(*s, va_arg(ap, void *));
			else
				chars += check_char(*s, 1);
			mode *= -1;
		}
		else
			putchar_check(s, 1, &chars);
		s++;
	}
	return (chars);
} */

int	print_var(const char *s, va_list ap)
{
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_putnbr_count(va_arg(ap, int), 1));
	else if (*(s + 1) == 'c')
		return (ft_putchar_fd_count(va_arg(ap, int), 1));
	else if (*(s + 1) == 'u')
		return (ft_putud_fd(va_arg(ap, unsigned int), 1));
	else if (*(s + 1) == 'x' || *(s + 1) == 'X')
		return (ft_puthex_fd(va_arg(ap, unsigned int), 1, *(s + 1)));
	else if (*(s + 1) == 's')
		return (ft_putstr_count(va_arg(ap, char *), 1));
	else if (*(s + 1) == 'p')
		return (ft_putptr_fd(va_arg(ap, void *), 1));
	else
		return(ft_putchar_fd_count(*(s + 1), 1));
}


int	print_stuff(const char *s, va_list ap)
{
	int	chars;

	chars = 0;
	while (1)
	{
		if (*s == 0)
			break ;
		if (*s == '%' && ft_strchr("dicuxXsp%" ,*(s + 1)))
		{
			chars += print_var(s, ap);
			s++;
		}
		else
			chars += ft_putchar_fd_count(*s, 1);
		s++;
	}
	return (chars);
}
