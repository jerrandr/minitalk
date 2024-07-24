/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrandr <jerrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:20:55 by jerrandr          #+#    #+#             */
/*   Updated: 2024/07/24 10:54:48 by jerrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
#define LIBFT_UTILS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
size_t			ft_strlen(char const *str);
char			*ft_strdup(const char *s);
long long int	ft_atoi(const char *nptr);
void			put_nbr(int	nbr);
#endif