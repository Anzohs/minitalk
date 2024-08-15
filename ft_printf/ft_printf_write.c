/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:33:17 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:11 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlong(int c)
{
	ft_putnbr_fd(c, 1);
	return (ft_leng_num(c));
}

int	ft_leng_num(int c)
{
	long	l;
	int		result;

	l = c;
	result = 0;
	if (l < 0)
	{
		l *= -1;
		result++;
	}
	while (l >= 10)
	{
		l /= 10;
		result++;
	}
	return (++result);
}

int	ft_write_string(char *string)
{
	int	i;

	i = 0;
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (*string)
		i += ft_printf_write(*string++);
	return (i);
}

int	ft_printf_write(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
