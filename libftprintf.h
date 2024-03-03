/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/03/02 14:22:58 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"

int	ft_printf(const char *src, ...);
int	count_args(const char *src);
int	print_stuff(const char *s, va_list ap);
int	ft_putptr_fd(void *p, int fd);
int	ft_putud_fd(unsigned int n, int fd);
int	ft_puthex_fd(unsigned int n, int fd, char cse);
int	ft_putnbr_count(int v, int fd);
int	ft_putstr_count(char *v, int fd);
int	ft_putchar_fd_count(char c, int fd);

#endif
