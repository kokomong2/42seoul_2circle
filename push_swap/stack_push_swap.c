/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:27:31 by sgo               #+#    #+#             */
/*   Updated: 2023/10/05 23:08:25 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_a(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	info->stack_a[info->size_a - 1] = info->stack_a[info->size_a - 2];
	info->stack_a[info->size_a - 2] = tmp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->stack_a[info->size_b - 1];
	info->stack_a[info->size_b - 1] = info->stack_a[info->size_b - 2];
	info->stack_a[info->size_b - 2] = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_info *info)
{
	int	tmp;

	write(1, "ss\n", 3);
	if (info->size_a < 2 || info->size_b < 2)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	info->stack_a[info->size_a - 1] = info->stack_a[info->size_a - 2];
	info->stack_a[info->size_a - 2] = tmp;
	tmp = info->stack_a[info->size_b - 1];
	info->stack_a[info->size_b - 1] = info->stack_a[info->size_b - 2];
	info->stack_a[info->size_b - 2] = tmp;
}

void	ft_push_a(t_info *info)
{
	if (info->size_b == 0)
		return ;
	info->stack_a[info->size_a] = info->stack_b[info->size_b - 1];
	info->size_a++;
	info->size_b--;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_info *info)
{
	if (info->size_a == 0)
		return ;
	info->stack_b[info->size_b] = info->stack_a[info->size_a - 1];
	info->size_b++;
	info->size_a--;
	write(1, "pb\n", 3);
}
