/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:22 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 15:32:12 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    wait_finish(t_philo *philos, t_args *args)
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
		// pthread_mutex_lock(&args->finish_mutex);
        // if (args->fin_cnt == args->philo_num)
        // {
		//     pthread_mutex_unlock(&args->finish_mutex);
        //     return (FALSE);
        // }
		// pthread_mutex_unlock(&args->finish_mutex);
    }
    return ;
}
