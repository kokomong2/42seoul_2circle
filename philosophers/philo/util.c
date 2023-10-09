/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:38:40 by sgo               #+#    #+#             */
/*   Updated: 2023/10/05 17:19:26 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	getres(unsigned long res, int sign, const char *str, size_t i);

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (getres(res, sign, str, i));
}

static int	getres(unsigned long res, int sign, const char *str, size_t i)
{
	int				j;
	unsigned long	tmp;

	while ('0' <= str[i] && str[i] <= '9')
	{
		tmp = res;
		j = 10;
		while (--j)
		{
			if (res >= -(unsigned long)LONG_MIN && sign == -1)
				return ((int)LONG_MIN);
			res = res + tmp;
			if (res > LONG_MAX && sign == 1)
				return ((int)LONG_MAX);
			if (res > -(unsigned long)LONG_MIN && sign == -1)
				return ((int)LONG_MIN);
		}
		if (res == LONG_MAX - 7 && sign == 1 && str[i] > '7')
			return ((int)LONG_MAX);
		if (res == LONG_MAX - 8 && sign == -1 && str[i] > '8')
			return ((int)LONG_MIN);
		res = res + (str[i] - '0');
		i++;
	}
	return ((int)(sign * (long)res));
}
