/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:28:45 by hugoladeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <sys/_types/_null.h>

static void	message_recieve(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Message recieve");
		exit(0);
	}
}

void	send_len(size_t len, int pid)
{
	int bit;

	bit = 0;

	while (bit < 32)
	{
		if ((len & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	size_t	len;
	struct sigaction	act;

	i = 0;
	act.sa_handler = message_recieve;
	if (argc == 3)
	{
		sigaction(SIGUSR2, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		pid = ft_atoi(argv[1]);
		if (pid < 1)
		{
			ft_printf("The value of the pid should be");
			ft_printf(" positive");
			return (0);
		}
		len = ft_strlen(argv[2]);
		send_len(len, pid);
		ft_printf("length sent \n");
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("Wrong number of arguments.\n");
	return (0);
}
