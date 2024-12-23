/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:44:54 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 18:39:35 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int argc, char *argv[], t_args *args)
{
	args->philo_num = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->must_eat = ft_atoi(argv[5]);
		if (args->must_eat <= 0)
			return (ERROR);
	}
	else
		args->must_eat = 0;
	if (args->philo_num <= 0 || args->time_eat <= 0 || args->time_die <= 0 \
		|| args->time_sleep <= 0)
		return (ERROR);
	args->fin_cnt = 0;
	args->finish = 0;
	pthread_mutex_init(&args->finish_mutex, NULL);
	pthread_mutex_init(&args->print_mutex, NULL);
	if (init_fork(args) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	init_fork(t_args *args)
{
	int	index;

	index = 1;
	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
					* (args->philo_num + 1));
	if (!args->forks)
		return (ERROR);
	while (index <= args->philo_num)
	{
		pthread_mutex_init(&(args->forks[index]), NULL);
		index++;
	}
	return (SUCCESS);
}

t_philo	*init_philos(t_args *args)
{
	t_philo	*philos;
	int		index;
	int		tmp;

	index = 1;
	philos = (t_philo *)malloc(sizeof(t_philo) * (args->philo_num + 1));
	if (!philos)
		return (NULL);
	while (index <= args->philo_num)
	{
		philos[index].philo_id = index;
		philos[index].args = args;
		philos[index].l_fork = index;
		philos[index].r_fork = index % args->philo_num + 1;
		if (index % 2 == 0)
		{
			tmp = philos[index].l_fork;
			philos[index].l_fork = philos[index].r_fork;
			philos[index].r_fork = tmp;
		}
		pthread_mutex_init(&philos[index].last_eat_mutex, NULL);
		philos[index].eat_cnt = 0;
		index++;
	}
	return (philos);
}
