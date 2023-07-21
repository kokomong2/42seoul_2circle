/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:29 by sgo               #+#    #+#             */
/*   Updated: 2023/07/20 21:04:35 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ra(t_info *info)
{
	int	tmp;
	int	i;

	if (info->top_index_a - info->bottom_index_a == 0)
		return ;
	tmp = info->stack_a[info->top_index_a - 1];
	i = info->top_index_a - 1;
	while (i > info->bottom_index_a)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[info->bottom_index_a] = tmp;
}

void	ft_rb(t_info *info)
{
	int	tmp;
	int	i;

	if (info->top_index_b - info->bottom_index_b == 0)
		return ;
	tmp = info->stack_b[info->top_index_b - 1];
	i = info->top_index_b - 1;
	while (i > info->bottom_index_b)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[info->bottom_index_b] = tmp;
}

void	ft_rr(t_info *info)
{
	ft_ra(info);
	ft_rb(info);
}