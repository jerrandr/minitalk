/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:12:20 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 13:16:07 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (str[count])
	{
		while (i < 8)
		{
			if (((str[count] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			if (((str[count] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			i++;
		}
		i = 0;
		count++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (!pid)
		return (0);
	if (argc == 3)
		ft_send(pid, argv[2]);
	else
		write(1, "Error\n", 6);
}