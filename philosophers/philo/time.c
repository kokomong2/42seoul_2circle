/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:23:58 by sgo               #+#    #+#             */
/*   Updated: 2023/10/11 19:16:10 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(t_args *args)
{
    long long       res;
    struct timeval  time;

    gettimeofday(&time, NULL);
    res = (long long)(time.tv_sec - args->first_time.tv_sec) * 1000 + \
    (long long)(time.tv_usec - args->first_time.tv_usec) / 1000;
    return (res);
}
