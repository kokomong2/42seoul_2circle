/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:38:40 by sgo               #+#    #+#             */
/*   Updated: 2023/10/13 17:28:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)res);
}

void	finish_eating(t_args *args)
{
	int	tmp;

	pthread_mutex_lock(&args->finish_mutex);
	args->fin_cnt++;
	tmp = args->fin_cnt;
	pthread_mutex_unlock(&args->finish_mutex);
	if (tmp == args->philo_num)
	{
		pthread_mutex_lock(&args->print_mutex);
		args->finish = 1;
		pthread_mutex_unlock(&args->print_mutex);
	}
}