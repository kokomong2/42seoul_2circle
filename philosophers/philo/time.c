/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:23:58 by sgo               #+#    #+#             */
/*   Updated: 2023/10/09 18:09:19 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(t_args *args)
{
    int res;
    struct timeval time;

    gettimeofday(&time, NULL);
    res = (int)(time.tv_sec - args->first_time.tv_sec) * 1000 + \
    (int)(time.tv_usec - args->first_time.tv_usec) / 1000;
    return res;
}
