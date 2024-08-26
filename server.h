/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:25:43 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:33:00 by hugoladeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	char	*c;
	size_t	len;
	int		bit;
	int		i;
	int		z;
}		t_data;

void	signal_handler(int signal);

#endif
