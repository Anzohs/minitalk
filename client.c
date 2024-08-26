/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/26 19:25:50 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>

static void	message_recieve(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\e[30mMessage recieve\n");
		exit(0);
	}
}

void	send_len(size_t len, int pid)
{
	int		bit;

	bit = 31;
	while (bit >= 0)
	{
		if ((len >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(50000);
	}
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50000);
	}
}

static void	check(int pid, int len, char *string)
{
	if (pid < 1 || kill(pid, 0) == -1)
	{
		ft_printf("check your pid \n");
		exit(0);
	}
	if (len < 1)
	{
		ft_printf("check your message \n");
		exit(0);
	}
	send_len(len, pid);
	while (*string != '\0')
	{
		send_bits(pid, *string);
		string++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					pid;
	int					i;
	int					len;

	i = 0;
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_handler = message_recieve;
	act.sa_flags = SA_SIGINFO;
	if (argc == 3)
	{
		sigaction(SIGUSR2, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		check(ft_atoi(argv[1]), ft_strlen(argv[2]), argv[2]);
		while (1)
			pause();
	}
	else
		ft_printf("Wrong number of arguments.\n");
	return (0);
}
