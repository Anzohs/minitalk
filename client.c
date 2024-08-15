/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/08/15 18:40:56 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	use_kill(char *pid)
{
	kill(ft_atoi(pid), SIGUSR1);
	ft_printf("signal was sent \n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		use_kill(argv[1]);
	else
		ft_printf("Bad number of arguments, it should be 1 argument");
	return (0);
}
