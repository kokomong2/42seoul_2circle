/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:29 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 16:32:34 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ra(t_info *info)
{
	int	tmp;
	int	i;

	if (info->size_a - info->bottom_index_a == 0)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	i = info->size_a - 1;
	while (i > info->bottom_index_a)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[info->bottom_index_a] = tmp;
	write(1, "ra\n", 3);
}

void	ft_rb(t_info *info)
{
	int	tmp;
	int	i;

	if (info->size_b - info->bottom_index_b == 0)
		return ;
	tmp = info->stack_b[info->size_b - 1];
	i = info->size_b - 1;
	while (i > info->bottom_index_b)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[info->bottom_index_b] = tmp;
	write(1, "rb\n", 3);
}

void	ft_rr(t_info *info)
{
	int	tmp;
	int	i;

	write(1, "rr\n", 3);
	if (info->size_a - info->bottom_index_a == 0)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	i = info->size_a - 1;
	while (i > info->bottom_index_a)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[info->bottom_index_a] = tmp;
	if (info->size_b - info->bottom_index_b == 0)
		return ;
	tmp = info->stack_b[info->size_b - 1];
	i = info->size_b - 1;
	while (i > info->bottom_index_b)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[info->bottom_index_b] = tmp;
}
