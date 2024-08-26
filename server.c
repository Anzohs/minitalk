/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:42:42 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/26 19:35:50 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/types.h>

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

static void	handle_data(t_data *data, int pid)
{
	if (data->len && data->bit == 8)
	{
		write_string(data->c, data->i, data->len);
		data->bit = 0;
		data->i = 0;
		data->z++;
	}
	if (data->len && data->len == data->z)
	{
		print_free(data->c);
		kill(pid, SIGUSR1);
		data->len = 0;
		data->bit = 0;
		data->i = 0;
		data->z = 0;
	}
}

static void	server_handler(int signal, siginfo_t *siginfo, void *context)
{
	static t_data	data;

	if (signal == SIGUSR1 && !data.len)
		data.i |= 1 << (31 - data.bit);
	else if (signal == SIGUSR1)
		data.i |= 1 << (7 - data.bit);
	data.bit++;
	if (data.len == 0 && data.bit == 32)
	{
		data.len = data.i;
		data.i = 0;
		data.bit = 0;
		data.c = (char *)ft_calloc(data.len + 2, sizeof(char));
		data.c[data.len] = '\n';
	}
	else
		handle_data(&data, siginfo->si_pid);
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_action;
	size_t				len;

	ft_bzero(&s_action, sizeof(struct sigaction));
	s_action.sa_sigaction = server_handler;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf("server pid : %i \n", getpid());
	while (1)
		pause();
}
