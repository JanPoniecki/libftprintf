/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:48:15 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/01 15:48:24 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *src, ...)
{
	int		chars;
	va_list	ap;

	va_start(ap, src);
	chars = print_stuff(src, ap);
	va_end(ap);
	return (chars);
}
/*
#include <stdio.h>
int main()
{
	// char *test = "test_string";
	char *test = NULL;
	int res1 = ft_printf("test numer %d, %c, %i, %u, %x, %X, %s, %p, %% %w %\n", 123, 'a', 333, -1, 23445, 324213, test, test);
	int res2 = printf("test numer %d, %c, %i, %u, %x, %X, %s, %p, %% %w %\n", 123, 'a', 333, -1, 23445, 324213, test, test);
	printf("%d  %d  \n", res1, res2);
	return (0);
}
*/
