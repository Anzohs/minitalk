/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:42:42 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:30:58 by hugoladeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

static void	print_free(char *string)
{
	ft_printf("%s", string);
	if (*string)
		free(string);

}

static void	write_string(char *c, int s, size_t len)
{
	static int	i;

	c[i++] = s;
	if (len == i)
		i = 0;
}

static void	server_handler(int signal, siginfo_t *siginfo, void *context)
{
	static size_t	len;
	static char		*c;
	static int	bit;
	static int	i;
	static int 	z;

	if (signal == SIGUSR1)
		i |= 1 << bit;
	bit++;
	if (len == 0 && bit == 32)
	{
		len = i;
		i = 0;
		bit = 0;
		c = (char *)ft_calloc(len + 1, sizeof(char));
	}
	if (len != 0 && bit == 8)
	{
		write_string(c, i, len);
		bit = 0;
		i = 0;
		z++;
	}
	if (len && len == z)
	{
		print_free(c);
		kill(siginfo->si_pid, SIGUSR1);
		len = 0;
		bit = 0;
		i = 0;
		z = 0;
	}
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_action;
	size_t				len;

	ft_bzero(&s_action, sizeof(struct sigaction));
	s_action.sa_handler = (void(*)(int))server_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf("server pid : %i \n", getpid());
	while (1)
		pause();
}
