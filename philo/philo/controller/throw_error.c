/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:33 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/27 13:39:32 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_message(int	status)
{
	if (status == ARGC_ERROR)
		ft_putstr_fd("You can only enter 4 or 5 arguments\n", 2);
	else if (status == INT_ERROR)
		ft_putstr_fd("Arguments are accepted only if they are positive integers\n", 2);
	else if (status == ERR_200)
		ft_putstr_fd("You can not enter more than 200 philosophers\n", 2);
	else if (status == MUTEX_ERR)
		ft_putstr_fd("There was an error occured while initializing mutex\n", 2);
	else if (status == THREAD_ERR)
		ft_putstr_fd("There was an error occured while creating one of the threads\n", 2);
	return (0);
}