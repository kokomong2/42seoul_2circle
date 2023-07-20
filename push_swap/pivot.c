/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:59:27 by sgo               #+#    #+#             */
/*   Updated: 2023/07/20 18:22:10 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_pivot(t_info *info, int array_size)
{
	int	upivot;
	int	dpivot;

	upivot = (array_size * 2) / 3;
	dpivot = array_size / 3;
	while (array_size--)
	{
		if (info->stack_a[info->top_index_a - 1] < dpivot)
		{
			ft_push_b(info);
			ft_rotate_b(info);
		}
		else if (info->stack_a[info->top_index_a - 1] < upivot)
			ft_push_b(info);
		else
			ft_rotate_a(info);
		print_stack(info);
	}
	while (info->top_index_a - info->bottom_index_a)
		ft_push_b(info);
}

