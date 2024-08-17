/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:42:42 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/17 17:25:55 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_message(int sig)
{
	static int	bit;
	static int	i;
	if (sig == SIGUSR1)
		i |= 1 <<  bit;
	bit ++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

void	server_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM)
		ft_printf("The server won't die \n");
	else if (signal == SIGUSR1 || signal == SIGUSR2)
		write_message(signal);
	else
		ft_printf("signal not supported \n");
}

int	main(void)
{
	g_s_action.sa_flags = 0;
	g_s_action.sa_handler = server_handler;
	ft_printf("server pid : %i \n", getpid());
	sigaction(SIGUSR1, &g_s_action, NULL);
	sigaction(SIGUSR2, &g_s_action, NULL);
	sigaction(SIGINT, &g_s_action, NULL);
	sigaction(SIGTERM, &g_s_action, NULL);
	while (1)
		pause();
}
