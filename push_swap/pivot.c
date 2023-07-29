/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:59:27 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 16:30:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bottom;

	top = info->stack_a[2];
	mid = info->stack_a[1];
	bottom = info->stack_a[0];
	if (top > mid && mid < bottom && top < bottom)
		ft_swap_a(info);
	if (top > mid && mid > bottom && top > bottom)
	{
		ft_swap_a(info);
		ft_rra(info);
	}
	if (top > mid && mid < bottom && top > bottom)
		ft_ra(info);
	if (top < mid && mid > bottom && top < bottom)
	{
		ft_swap_a(info);
		ft_ra(info);
	}
	if (top < mid && mid > bottom && top > bottom)
		ft_rra(info);
}

void	get_pivot(t_info *info, int array_size)
{
	int	upivot;
	int	dpivot;

	upivot = (array_size * 2) / 3;
	dpivot = array_size / 3;
	while (array_size--)
	{
		if (info->stack_a[info->size_a - 1] < dpivot)
		{
			ft_push_b(info);
			ft_rb(info);
		}
		else if (info->stack_a[info->size_a - 1] < upivot)
			ft_push_b(info);
		else
			ft_ra(info);
	}
	while (info->size_a > 3)
		ft_push_b(info);
}
