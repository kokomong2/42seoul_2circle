/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:44:46 by sgo               #+#    #+#             */
/*   Updated: 2023/10/11 21:16:07 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mutex_printf(t_philo *philo, long long time, char *msg)
{
    t_args *args;
    int     result;

    args = philo->args;
    result = FALSE;
	pthread_mutex_lock(&args->print_mutex);
    if (args->finish == 0)
    {
        if (msg == NULL)
        {
            args->finish = 1;
            msg = MSG_DIED;
        }
        printf("%lld %d %s\n", time, philo->philo_id, msg);
        result = SUCCESS;
    }
	pthread_mutex_unlock(&args->print_mutex);
    return (result);
}

int    print_error(char *msg)
{
   printf(RED"%s\n", msg);
   return (ERROR);
}
