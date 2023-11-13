/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:20:29 by metyasar          #+#    #+#             */
/*   Updated: 2023/09/14 16:59:54 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

void	send_to_server(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 128) == 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		i++;
		usleep(50);
	}
}

void	send_message(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_to_server(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*msg;
	int		spid;

	if (ac != 3)
	{
		write(1, "wrong number of arguments..\n", 28);
		return (1);
	}
	spid = ft_atoi(av[1]);
	msg = av[2];
	send_message(msg, spid);
	return (0);
}
