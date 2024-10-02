/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:49:25 by erkoc             #+#    #+#             */
/*   Updated: 2024/10/02 16:17:38 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_simulation(void *arg)
{ 
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (TRUE)
	{
		if (philo->meal_count == philo->program->loopct || philo->program->is_dead)
			break ;
		if (!odd_ones_take_forks(philo) || !odd_ones_eat_pasta(philo))
			break ;
		if (!even_ones_take_forks(philo) || !even_ones_eat_pasta(philo))
			break ;
		if (!everybody_sleeps(philo)) // || !everybody_thinks(philo)
			break ;
		is_anybody_dead(philo);
		if (philo->program->is_dead)
			break ;
	}
	return (NULL);
}

int main(int argc, char **argv) // ./philo philo_count, açlıksüresi, time_to_eat, uyumasüresi, kaç kere yicekler(opsiyonel) 
{
	t_program prog;

	if (!controls(argc, argv))
		return (1);
	fill_struct(&prog, argv);
	if (!init_mutexes(&prog))
		return (1);
	if (!init_philosophers(&prog))
		return (1);
	if (!create_philosphers(&prog))
		return (1);
	if (!wait_for_philosophers(&prog))
		return (1);

}