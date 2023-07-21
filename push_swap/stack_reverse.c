/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:59:16 by sgo               #+#    #+#             */
/*   Updated: 2023/07/21 18:46:51 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rra(t_info *info)
{
	int	tmp;
	int	i;

	if (info->top_index_a - info->bottom_index_a == 0)
		return ;
	tmp = info->stack_a[info->bottom_index_a];
	i = info->bottom_index_a;
	while (i < info->top_index_a - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	info->stack_a[info->top_index_a - 1] = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_info *info)
{
	int	tmp;
	int	i;

	if (info->top_index_b - info->bottom_index_b == 0)
		return ;
	tmp = info->stack_b[info->bottom_index_b];
	i = info->bottom_index_b;
	while (i < info->top_index_b - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->stack_b[info->top_index_b - 1] = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_info *info)
{
	int	tmp;
	int	i;

	write(1, "rrr\n", 4);
	if (info->top_index_a - info->bottom_index_a == 0)
		return ;
	tmp = info->stack_a[info->bottom_index_a];
	i = info->bottom_index_a;
	while (i < info->top_index_a - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	info->stack_a[info->top_index_a - 1] = tmp;
	if (info->top_index_b - info->bottom_index_b == 0)
		return ;
	tmp = info->stack_b[info->bottom_index_b];
	i = info->bottom_index_b;
	while (i < info->top_index_b - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->stack_b[info->top_index_b - 1] = tmp;
}
