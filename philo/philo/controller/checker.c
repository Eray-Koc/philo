/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:01:49 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/28 13:17:55 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int	integer_checker(char **argv)
{
	int	i;
	int	j;
	i = 1;
	while (argv[i]) 
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	controls(int ac, char **argv)
{
	if (ac < 5 || ac > 6)
		return (print_message(ARGC_ERROR));
	if (!integer_checker(argv))
		return (print_message(INT_ERROR));
	if (ft_atoi(argv[1]) > 200)
		print_message(ERR_200);
	return (1);
}