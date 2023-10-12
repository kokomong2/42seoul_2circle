/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:15:39 by sgo               #+#    #+#             */
/*   Updated: 2023/10/12 19:34:53 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_fork(t_args *args, t_philo *philo);
int	eating(t_args *args, t_philo *philo);
int	sleep_think(t_args *args, t_philo *philo);

void    *dining(t_philo *philo)
{	
	t_args *args;

	args = philo->args;
	philo->last_eat = get_time(args);
	while (1)
	{
		if (philo->philo_id % 2 == 0)
			usleep(300);
		if (pick_fork(args, philo) == FALSE)
			return (NULL);
		if (eating(args, philo) == FALSE)
			return (NULL);
		if (sleep_think(args, philo) == FALSE)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

int	start_dining(t_philo *philos, t_args *args)
{
	int	index;

	index = 1;
	while (index <= args->philo_num)
	{
		if (pthread_create(&philos[index].thread, NULL, (void *)dining, &(philos[index])))
			return (ERROR);
		index++;
	}
	return (SUCCESS);
}

int	pick_fork(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&args->forks[philo->l_fork]);
	if (mutex_printf(philo, get_time(args), MSG_FORK) == FALSE || \
		args->philo_num == 1)
	{
		pthread_mutex_unlock(&args->forks[philo->l_fork]);
		return (FALSE);
	}
	pthread_mutex_lock(&args->forks[philo->r_fork]);
	if (mutex_printf(philo, get_time(args), MSG_FORK) == FALSE)
	{
		pthread_mutex_unlock(&args->forks[philo->l_fork]);
		pthread_mutex_unlock(&args->forks[philo->r_fork]);
		return (FALSE);
	}
	return (SUCCESS);
}

int	eating(t_args *args, t_philo *philo)
{
	if (mutex_printf(philo, get_time(args), MSG_EATING) == FALSE)
	{
		pthread_mutex_unlock(&args->forks[philo->l_fork]);
		pthread_mutex_unlock(&args->forks[philo->r_fork]);
		return (FALSE);
	}
	philo->eat_cnt++;
	if (philo->eat_cnt == args->must_eat)
	{
		pthread_mutex_lock(&args->finish_mutex);
		args->fin_cnt++;
		pthread_mutex_unlock(&args->finish_mutex);
	}
	if (args->fin_cnt == args->philo_num)
	{
		pthread_mutex_lock(&args->print_mutex);
		args->finish = 1;
		pthread_mutex_unlock(&args->print_mutex);
	}
	philo->last_eat = get_time(args);
	ft_usleep(args->time_eat, args);
	pthread_mutex_unlock(&args->forks[philo->l_fork]);
	pthread_mutex_unlock(&args->forks[philo->r_fork]);
	return (SUCCESS);
}

int	sleep_think(t_args *args, t_philo *philo)
{
	if (mutex_printf(philo, get_time(args), MSG_SLEEPING) == FALSE)
		return (FALSE);
	ft_usleep(args->time_sleep, args);
	if (mutex_printf(philo, get_time(args), MSG_THINKING) == FALSE)
		return (FALSE);
	return (SUCCESS);
}
