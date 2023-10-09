/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:44:46 by sgo               #+#    #+#             */
/*   Updated: 2023/10/09 17:42:52 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mutex_printf(t_philo *philo, int time, char *msg)
{
    t_args *args;
    int     result;

    args = philo->args;
    result = FALSE;
    pthread_mutex_lock(&philo->args->print_mutex);
    if (args->fin_cnt < args->philo_num)
    {
        if (msg == NULL)
        {
            args->fin_cnt = args->must_eat;
            msg = MSG_DIED;
            args->finish = 1;
        }
        printf("%d %d %s\n", time, philo->philo_id, msg);
        result = SUCCESS;
    }
    pthread_mutex_unlock(&philo->args->print_mutex);
    return (result);
}
