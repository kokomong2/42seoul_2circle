/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:06:27 by sgo               #+#    #+#             */
/*   Updated: 2023/10/11 20:32:28 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo, t_args *args)
{
	int	index;

	index = 1;
	while (index <= args->philo_num)
	{
		pthread_mutex_lock(&args->finish_mutex);
		if (args->fin_cnt == args->philo_num)
		{
			pthread_mutex_unlock(&args->finish_mutex);
			return ;
		}
		pthread_mutex_unlock(&args->finish_mutex);
		if (get_time(args) - philo[index].last_eat > args->time_die)
		{
			mutex_printf(&philo[index], get_time(args), NULL);
			return ;
		}
		index = (index % args->philo_num) + 1;
		usleep(150);
	}
}
