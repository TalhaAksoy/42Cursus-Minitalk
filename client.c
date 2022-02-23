/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:55:05 by saksoy            #+#    #+#             */
/*   Updated: 2022/02/23 17:35:46 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char c;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		ft_printf("yanlış girdin kanka");
		return (0);
	}
	while (argv[2][i] && argv[2])
	{
		j = 8;
		c = argv[2][i++];
		while (j--)
		{
			if (c >> j & 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(200);
		}
	}
	i = 8;
	while (i--)
	{
		kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(200);
	}
}
