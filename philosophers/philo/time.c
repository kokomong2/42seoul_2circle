/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:23:58 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 15:58:12 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   get_time(t_philo *philo)
{
    long long       res;
    struct timeval  time;

    gettimeofday(&time, NULL);
    res = (long long)((time.tv_sec - philo->start_time.tv_sec) * 1000 + \
    (time.tv_usec - philo->start_time.tv_usec) / 1000);
    return (res);
}
