/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:27:31 by sgo               #+#    #+#             */
/*   Updated: 2023/07/19 19:52:01 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_a(t_info *info)
{
	int	tmp;

	if (info->top_index_a - info->bottom_index_a < 2)
		return ;
	tmp = info->stack_a[info->top_index_a - 1];
	info->stack_a[info->top_index_a - 1] = info->stack_a[info->top_index_a - 2];
	info->stack_a[info->top_index_a - 2] = tmp;
}

void	ft_swap_b(t_info *info)
{
	int	tmp;

	if (info->top_index_b - info->bottom_index_b < 2)
		return ;
	tmp = info->stack_a[info->top_index_b - 1];
	info->stack_a[info->top_index_b - 1] = info->stack_a[info->top_index_b - 2];
	info->stack_a[info->top_index_b - 2] = tmp;
}

void	ft_ss(t_info *info)
{
	ft_swap_a(info);
	ft_swap_b(info);
}

void	ft_push_a(t_info *info)
{
	if (info->top_index_b - info->bottom_index_b == 0)
		return ;
	info->stack_a[info->top_index_a] = info->stack_b[info->top_index_b - 1];
	info->top_index_a++;
	info->top_index_b--;
}

void	ft_push_b(t_info *info)
{
	if (info->top_index_a - info->bottom_index_a == 0)
		return ;
	info->stack_b[info->top_index_b] = info->stack_a[info->top_index_a - 1];
	info->top_index_b++;
	info->top_index_a--;
}