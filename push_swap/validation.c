/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:28 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 16:32:46 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error()
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
