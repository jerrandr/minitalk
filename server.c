/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:12:43 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 13:28:47 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_add_car(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i++] = '\0';
	return (res);
}

int	ft_power(int nbr, int power)
{
	int	i;

	i = 1;
	if (nbr == 0 || power == 0)
		return (0);
	while (i <= power)
	{
		nbr = nbr * i;
		i++;
	}
	return (nbr);
}
void print_binary(int n) {
    // Déterminer le nombre de bits dans un entier
    int num_bits = sizeof(n) * 8;

    printf("Binary representation of %d: ", n);
    for (int i = num_bits - 1; i >= 0; i--) {
        // Utiliser un masque pour vérifier chaque bit
        int mask = 1 << i;
        printf("%d", (n & mask) ? 1 : 0);
    }
    printf("\n");
}
void	ft_put_message(int	nbr)
{
	static int		counter;
	static int		tmp;
	static char		*res_final;

	printf("nbr == %d\n", nbr);
	if (!res_final)
		res_final = NULL;
	if (nbr == SIGUSR1)
		tmp = tmp + 0;
	if (nbr == SIGUSR2)
		tmp = tmp + (1 * ft_power(2, 7 - counter));
	printf("%d\n", tmp);
	print_binary(tmp);
	counter++;
	// if (counter == 8)
	// {
	// 	res_final = ft_add_car(res_final, tmp);
	// 	counter = 0;
	// 	tmp = 0;
	// }
}

int	main(void)
{
	struct sigaction	signal_arrived;

	put_nbr(getpid());
	write(1, "\n", 1);
	signal_arrived.sa_handler = ft_put_message;
	signal_arrived.sa_flags = 0;
	sigaction(SIGUSR1, &signal_arrived, NULL);
	sigaction(SIGUSR2, &signal_arrived, NULL);
	while (1)
		usleep(50);
}