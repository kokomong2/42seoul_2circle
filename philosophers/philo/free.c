/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:43:44 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 00:07:02 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_args(t_args *args)
{
	int	i;

	i = 1;
	pthread_mutex_destroy(&args->finish_mutex);
	pthread_mutex_destroy(&args->print_mutex);
	while (i <= args->philo_num)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	free(args->forks);
	args->forks = NULL;
}

void	free_philos(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i <= args->philo_num)
	{
		philo->args = NULL;
		i++;
	}
	free(philo);
	philo = NULL;
}
