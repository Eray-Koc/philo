/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:49:33 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/30 14:53:52 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

# define FALSE 0
# define TRUE 1


typedef struct s_philo
{
	int id;
	int	meal_count;
	int	l_fork;
	int	r_fork;
	long long last_meal;
	struct s_program *program;
}	t_philo;

typedef struct s_program
{
	int is_dead;
	int philo_count;
	int	hunger_time;
	int eat_time;
	int sleep_time;
	int loopct;
	long long start_time;
	t_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t g_mutex;
	pthread_t *philos;

} t_program;

typedef enum e_status
{
	ARGC_ERROR = 25,
	INT_ERROR,
	ERR_200,
	MUTEX_ERR,
	THREAD_ERR,
	JOIN_ERROR
} t_status;

/*---------------- MIINI LIB -----------------*/
/*--------------------------------------------*/
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);// dolayısıyla bu da 
char	*ft_itoa(long long n); //çıkarılabilir sanırım -->strdup 
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	ft_strlen(char *str);

/*--------------- PHILOSOPHERS ----------------*/
/*---------------------------------------------*/
int	print_message(int status);
int	controls(int ac, char **argv);
int	init_philosophers(t_program *program);
int	init_mutexes(t_program *program);
void	*start_simulation(void *arg);
void	fill_struct(t_program *program, char **argv);
int	create_philosphers(t_program *program);
long long get_cur_time_in_ms();
void	is_anybody_dead(t_philo *philo);
int	wait_for_philosophers(t_program *program);
void	print_status(t_philo *philo, char *str);
int	odd_ones_take_forks(t_philo *philo);
int	odd_ones_eat_pasta(t_philo *philo);
int	even_ones_take_forks(t_philo *philo);
int	even_ones_eat_pasta(t_philo *philo);
int	everybody_thinks(t_philo *philo);
int	everybody_sleeps(t_philo *philo);
void	ft_sleep(long long wait_time);
#endif

