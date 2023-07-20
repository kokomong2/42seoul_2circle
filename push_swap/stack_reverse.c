/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:59:16 by sgo               #+#    #+#             */
/*   Updated: 2023/07/19 20:06:36 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_reverse_a(t_info *info)
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
}

void	ft_reverse_b(t_info *info)
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
}

void	ft_rrr(t_info *info)
{
	ft_reverse_a(info);
	ft_reverse_b(info);
}
