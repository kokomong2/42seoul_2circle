/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:22 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 19:51:56 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_finish(t_philo *philos, t_args *args)
{
	int	index;

	index = 1;
	while (index <= args->philo_num)
	{
		pthread_join(philos[index].thread, NULL);
		index++;
	}
	return ;
}

int	ft_usleep(long long time, t_philo *philo)
{
	long long	end;
	t_args		*args;

	args = philo->args;
	end = get_time(philo) + time;
	while (get_time(philo) < end)
	{
		pthread_mutex_lock(&args->print_mutex);
		if (args->finish == 1)
		{
			pthread_mutex_unlock(&args->print_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&args->print_mutex);
		usleep(100);
	}
	return (SUCCESS);
}
