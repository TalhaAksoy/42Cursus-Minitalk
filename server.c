/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:51:36 by saksoy            #+#    #+#             */
/*   Updated: 2022/02/23 19:30:21 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static char	str = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		ft_printf("%c", str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_printf("process_id => %d\n", getpid());
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
	{
		pause();
	}
	return (0);
}
