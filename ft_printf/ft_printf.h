/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:37:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/30 19:15:26 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_write_string(char *string);
int	ft_leng_num(int c);
int	ft_printf_write(char c);
int	ft_putlong(int c);
int	ft_printf_bases(unsigned long c, char *bases);
int	ft_printf_unint(unsigned int c);
int	ft_printf_adr(void *ptr, char *base);

#endif