/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:27:06 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 08:28:12 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

long long int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	long long int		nbr;
	char				*tmp;

	tmp = (char *)nptr;
	nbr = 0;
	sign = 0;
	i = 0;
	if ((tmp[i] == '+') || (tmp[i] == '-'))
	{
		if (tmp[i] == '-')
			sign = 1;
		i++;
	}
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		nbr = (nbr * 10) + (tmp[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-nbr);
	return (nbr);
}