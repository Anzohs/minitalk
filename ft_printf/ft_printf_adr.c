/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:54 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/30 19:17:20 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_long_len(unsigned long l)
{
	int	i;

	i = 0;
	while (l >= 16)
	{
		l /= 16;
		i ++;
	}
	return (i + 1);
}

static void	ft_printf_hex(unsigned long l, char *base)
{
	if (l >= 16)
	{
		ft_printf_hex(l / 16, base);
	}
	ft_putchar_fd(base[l % 16], 1);
}

int	ft_printf_adr(void *ptr, char *base)
{
	unsigned long	i;
	int				result;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = (unsigned long)ptr;
	result = 0;
	ft_putstr_fd("0x", 1);
	result += 2;
	result += ft_long_len(i);
	ft_printf_hex(i, base);
	return (result);
}
