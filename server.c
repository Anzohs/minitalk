/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:42:42 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/20 20:22:03 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	write_message(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

void	server_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		write_message(signal);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_bzero(&s_action, sizeof(struct sigaction));
	s_action.sa_flags = 0;
	s_action.sa_handler = server_handler;
	ft_printf("server pid : %i \n", getpid());
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
}
