/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:03 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/30 15:46:11 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_cur_time_in_ms()
{
	struct timeval start;

	gettimeofday(&start, NULL);
	return ((start.tv_usec / 1000) + (start.tv_sec * 1000));
}

void	fill_struct(t_program *program, char **argv)
{
	program->is_dead = FALSE;
	program->philo_count = ft_atoi(argv[1]);
	program->hunger_time = ft_atoi(argv[2]);
	program->eat_time = ft_atoi(argv[3]);
	program->sleep_time = ft_atoi(argv[4]);
	program->loopct = -1;
	if (argv[5])
		program->loopct = ft_atoi(argv[5]);
}

int	init_philosophers(t_program *program)
{
	int	i;

	i = 0;
	program->philo = malloc(sizeof(t_philo) * program->philo_count);
	while (i < program->philo_count)
	{
		program->philo[i].id = i + 1;
		program->philo[i].l_fork = i;
		program->philo[i].r_fork = ((i + 1) % program->philo_count);
		program->philo[i].meal_count = 0;
		program->philo[i].program = program;
		i++;
	}
	return (1);
}

void	die_checker(t_program *program, int i)
{
	while (TRUE)
	{
		i = 0;
		while (program->philos[i])
		{
			if ((get_cur_time_in_ms() - program->philo[i].last_meal) > program->hunger_time)
			{
				print_status(&program->philo[i], "is dead");
				program->is_dead = TRUE;
				return ;
			}
			if (program->philo[i].meal_count == program->loopct)
				return ;
			i++;
		}
	}
}

int	create_philosphers(t_program *program)
{
	int	i;

	i = 0;
	program->start_time = get_cur_time_in_ms();
	program->philos = malloc(sizeof(pthread_t) * (program->philo_count + 1));
	program->philos[program->philo_count] = NULL;
	while (i < program->philo_count)
	{
		program->philo[i].last_meal = get_cur_time_in_ms();
		if (pthread_create(&program->philos[i], NULL, start_simulation, &program->philo[i]) != 0)
		{
			print_message(THREAD_ERR);
			return (0);
		}
		i++;
	}
	die_checker(program, 0);
	return (1);
}

int	init_mutexes(t_program *program)
{
	int	i;

	i = 0;
	pthread_mutex_init(&program->g_mutex, NULL);
	program->forks = malloc(sizeof(pthread_mutex_t) * program->philo_count);
	while (i < program->philo_count)
	{
		if (pthread_mutex_init(&program->forks[i], NULL) != 0)
		{
			print_message(MUTEX_ERR);
			return (0);
		}
		i++;
	}
	return (1);
}