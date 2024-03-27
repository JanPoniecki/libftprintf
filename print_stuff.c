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
