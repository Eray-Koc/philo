/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:30:04 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/25 16:30:12 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*str_new;
	size_t	x;

	x = 0;
	str = (char *)s1;
	str_new = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!str_new)
		return (NULL);
	while (str[x])
	{
		str_new[x] = str[x];
		x++;
	}
	str_new[x] = 0;
	return (str_new);
}