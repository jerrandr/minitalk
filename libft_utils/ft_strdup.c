/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:24:25 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 08:24:57 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tmp;
	int		n;

	n = 0;
	i = ft_strlen((char *)s);
	tmp = malloc((sizeof(char)) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	while (n < i)
	{
		tmp[n] = s[n];
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}