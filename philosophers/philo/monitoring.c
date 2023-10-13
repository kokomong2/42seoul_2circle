/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:06:27 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 07:30:15 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo, t_args *args)
{
	int	index;

	index = 1;
	usleep(400);
	while (index <= args->philo_num)
	{
		pthread_mutex_lock(&args->finish_mutex);
		if (args->fin_cnt == args->philo_num)
		{
			pthread_mutex_unlock(&args->finish_mutex);
			return ;
		}
		pthread_mutex_unlock(&args->finish_mutex);
		pthread_mutex_lock(&philo[index].last_eat_mutex);
		if (get_time(&philo[index]) - philo[index].last_eat > args->time_die)
		{
			pthread_mutex_unlock(&philo[index].last_eat_mutex);
			mutex_printf(&philo[index], NULL);
			return ;
		}
		pthread_mutex_unlock(&philo[index].last_eat_mutex);
		index = (index % args->philo_num) + 1;
		usleep(100);
	}
}
