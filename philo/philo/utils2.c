/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:30:05 by erkoc             #+#    #+#             */
/*   Updated: 2024/10/02 16:45:10 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long long wait_time)
{
	while (get_cur_time_in_ms() < wait_time)
	{
		usleep(10);
	}
}

void	is_anybody_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->g_mutex);
	if (philo->program->is_dead)
	{
		pthread_mutex_unlock(&philo->program->g_mutex);
		return ;
	}
	if ((get_cur_time_in_ms() - philo->last_meal) >= philo->program->hunger_time)
	{
		philo->program->is_dead =TRUE;
		print_status(philo, "is dead");
	}
	pthread_mutex_unlock(&philo->program->g_mutex);
}

void	print_status(t_philo *philo, char *str)
{
	if (philo->program->is_dead == FALSE)
	{
		printf("%llu ", (get_cur_time_in_ms() - philo->program->start_time));
		printf("%i ", philo->id);
		printf("%s\n", str);
	}
	
}

int	everybody_sleeps(t_philo *philo)
{
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	ft_sleep(philo->program->sleep_time + get_cur_time_in_ms());
	pthread_mutex_lock(&philo->program->g_mutex);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->program->g_mutex);
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	everybody_thinks(t_philo *philo)
{
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	//ft_sleep(get_cur_time_in_ms() + philo->program->sleep_time);
	pthread_mutex_lock(&philo->program->g_mutex);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->program->g_mutex);
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	odd_ones_eat_pasta(t_philo *philo)
{
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	if (philo->id % 2 != 0)
	{
		ft_sleep(philo->program->eat_time + get_cur_time_in_ms());
		pthread_mutex_unlock(&philo->program->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->program->forks[philo->r_fork]);
		pthread_mutex_lock(&philo->program->g_mutex);
		print_status(philo, "is sleeping");
		philo->last_meal = get_cur_time_in_ms();
		philo->meal_count++;
		pthread_mutex_unlock(&philo->program->g_mutex);
	}
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	odd_ones_take_forks(t_philo *philo)
{
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->program->forks[philo->r_fork]);
		pthread_mutex_lock(&philo->program->forks[philo->l_fork]);
		pthread_mutex_lock(&philo->program->g_mutex);
		print_status(philo, "has taken a fork");
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->program->g_mutex);
	}
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	even_ones_take_forks(t_philo *philo)
{
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->program->forks[philo->r_fork]);
		pthread_mutex_lock(&philo->program->forks[philo->l_fork]);
		pthread_mutex_lock(&philo->program->g_mutex);
		print_status(philo, "has taken a fork");
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->program->g_mutex);
	}
	is_anybody_dead(philo);
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	even_ones_eat_pasta(t_philo *philo)
{
	if (philo->program->is_dead)
		return (0);
	if (philo->id % 2 == 0)
	{
		ft_sleep(philo->program->eat_time + get_cur_time_in_ms());
		pthread_mutex_unlock(&philo->program->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->program->forks[philo->r_fork]);
		pthread_mutex_lock(&philo->program->g_mutex);
		print_status(philo, "is sleeping");
		pthread_mutex_unlock(&philo->program->g_mutex);
		philo->last_meal = get_cur_time_in_ms();
		philo->meal_count++;
		
	}
	if (philo->program->is_dead)
		return (0);
	return (1);
}

int	wait_for_philosophers(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_count)
	{
		if (pthread_join(program->philos[i], NULL) != 0)
		{
			print_message(JOIN_ERROR);
			return (0);
		}
		//else
		//	printf("%d numaralı filo joinlendi. \n", program->philo[i].id);
		i++;
	}
	return (1);
}