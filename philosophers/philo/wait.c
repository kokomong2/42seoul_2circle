/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:22 by sgo               #+#    #+#             */
/*   Updated: 2023/10/09 17:46:01 by sgo              ###   ########.fr       */
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

// int ft_usleep(int time, t_args *args)
// {
//     int i;

//     i = 0;
//     while (i < time)
//     {
//         if (args->fin_cnt )
//     }
// }