/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:20:23 by metyasar          #+#    #+#             */
/*   Updated: 2023/09/14 16:51:57 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		write(1, &"0123456789"[nbr], 1);
}

void	handle(int signal)
{
	static char	c;
	static int	i;

	i++;
	c <<= 1;
	if (signal == SIGUSR1)
		c++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	write(1, "pid is: ", 8);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
	{
		usleep(30);
	}
	return (0);
}
