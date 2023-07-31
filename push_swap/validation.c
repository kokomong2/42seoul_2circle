/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:28 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 20:47:21 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicate(t_info *info, int *array, int array_size, int check)
{
	int	i;

	i = 0;
	if (info->have_zero == 1 && check == 0)
		print_error();
	if (info->have_zero == 0 && check == 0)
		info->have_zero = 1;
	while (i < array_size)
	{
		if (check != 0 && array[i] == check)
			print_error();
		i++;
	}
}

int	is_all_blank(char *str)
{
	int	isblank;

	isblank = 1;
	while (*str)
	{
		if (*str != ' ')
			isblank = 0;
		str++;
	}
	return (isblank);
}
