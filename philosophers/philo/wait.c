/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:22 by sgo               #+#    #+#             */
/*   Updated: 2023/10/11 19:51:21 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int wait_finish(t_philo *philos, t_args *args)
{
    int index;

    index = 1;
    while (index <= args->philo_num)
    {
        if (pthread_join(philos[index].thread, NULL))
            return(ERROR);
        index++;
    }
    return (SUCCESS);
}

int ft_usleep(long long time, t_args *args)
{
    long long   start;  
	long long	end;

	end = get_time(args) + time;
	start = get_time(args);
    while (start < end)
    {
		usleep((end - start) * 200);
		pthread_mutex_lock(&args->finish_mutex);
        if (args->fin_cnt == args->philo_num)
        {
		    pthread_mutex_unlock(&args->finish_mutex);
            return (FALSE);
        }
		pthread_mutex_unlock(&args->finish_mutex);
		start = get_time(args);
    }
    return (SUCCESS);
}
