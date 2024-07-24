/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:51:38 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 13:05:25 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	put_nbr(int	nbr)
{
	char	tmp;

	if (nbr < 10)
	{
		tmp = nbr + '0';
		write(1, &tmp, 1);
	}
	else if (nbr >= 10)
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
}