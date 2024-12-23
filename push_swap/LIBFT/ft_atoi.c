/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:41:33 by sgo               #+#    #+#             */
/*   Updated: 2023/07/31 19:36:08 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	getres(unsigned long res, int sign, const char *str, size_t i);

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		print_error();
	return (getres(res, sign, str, i));
}

static int	getres(unsigned long res, int sign, const char *str, size_t i)
{
	int				j;
	unsigned long	tmp;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error();
		tmp = res;
		j = 10;
		res = res * 10 + (str[i] - '0');
		if (res > (unsigned long)INT_MAX + 1 && sign == -1)
			print_error();
		if (res > INT_MAX && sign == 1)
			print_error();
		i++;
	}
	return ((int)(sign * (long)res));
}
