/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:13:47 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/30 17:22:04 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_un_len(unsigned int c)
{
	int	i;

	i = 0;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_printf_unint(unsigned int c)
{
	int	i;
	int	p;

	i = ft_un_len(c);
	p = -1;
	if (c >= 10)
	{
		p = c % 10;
		ft_putnbr_fd(c / 10, 1);
	}
	if (p != -1)
		ft_putnbr_fd(p, 1);
	else
		ft_putnbr_fd(c, 1);
	return (i);
}
