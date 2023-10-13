/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:22 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 17:13:03 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	wait_finish(t_philo *philos, t_args *args)
{
	int index;

	index = 1;
	while (index <= args->philo_num)
	{
		pthread_join(philos[index].thread, NULL);
		index++;
	}
	return ;
}

void ft_usleep(long long time, t_args *args, t_philo *philo)
{
	long long	end;

	(void)args;
	end = get_time(philo) + time;
	usleep(time * 700);
	while (get_time(philo) < end)
	{
		usleep(100);
	}
	return ;
}
