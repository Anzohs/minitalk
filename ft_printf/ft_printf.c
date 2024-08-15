/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:50:43 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/15 17:36:51 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write(char c, va_list *list)
{
	if (c == 'c')
		return (ft_printf_write(va_arg(*list, int)));
	if (c == 's')
		return (ft_write_string(va_arg(*list, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putlong(va_arg(*list, int)));
	if (c == '%')
		return (ft_printf_write('%'));
	if (c == 'x')
		return (ft_printf_bases(va_arg(*list, unsigned int), \
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_printf_bases(va_arg(*list, unsigned int), \
				"0123456789ABCDEF"));
	if (c == 'u')
		return (ft_printf_unint(va_arg(*list, unsigned int)));
	if (c == 'p')
		return (ft_printf_adr(va_arg(*list, void *), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list_args;
	int		result;

	if (format == NULL || format == 0)
		return (-1);
	result = 0;
	va_start(list_args, format);
	while (*format)
	{
		if (*format == '%')
		{
			result += ft_write(*(format + 1), &list_args);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			result++;
		}
		format++;
	}
	return (result);
}
