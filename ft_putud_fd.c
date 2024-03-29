/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putud_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/03/02 14:18:37 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_ud(unsigned int nb, int fd)
{
	char	c;

	if (nb < 10)
	{
		c = nb + 48;
		write(fd, &c, 1);
	}
	else
	{
		write_ud(nb / 10, fd);
		write_ud(nb % 10, fd);
	}
}

int	ft_putud_fd(unsigned int nb, int fd)
{
	int	chars;

	write_ud(nb, fd);
	if (nb == 0)
		return (1);
	chars = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		chars++;
	}
	return (chars);
}
