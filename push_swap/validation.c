/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:28 by sgo               #+#    #+#             */
/*   Updated: 2023/07/24 15:31:00 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error()
{
	write(1,"Error\n", 6);
	exit(1);
}

void	check_duplicate(int *array, int array_size, int check)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (array[i] == check)
			print_error();
		i++;
	}
}