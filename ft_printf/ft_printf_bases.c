/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:18:19 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/15 17:36:35 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_bases(unsigned long i, char *base)
{
	if (i >= 16)
	{
		ft_write_bases((i / 16), base);
	}
	ft_putchar_fd(base[i % 16], 1);
}

int	ft_printf_bases(unsigned long c, char *bases)
{
	int	count;

	count = 0;
	ft_write_bases(c, bases);
	while (c >= 16)
	{
		c /= 16;
		count++;
	}
	return (count + 1);
}
