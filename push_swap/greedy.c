/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:59:21 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 16:30:20 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	set_a_location(int num, t_info *info)
{
	int	index;
	int	res;
	int	now;

	index = info->size_a;
	res = index;
	while (index--)
	{
		now = info->stack_a[index];
		if (num < now)
			if (res == info->size_a || info->stack_a[res] > now)
				res = index;
	}
	index = info->size_a;
	if (res == index)
	{
		res = index - 1;
		while (index--)
			if (info->stack_a[res] > info->stack_a[index])
				res = index;
	}
	if (res < (info->size_a / 2))
		res = -(res + 1);
	else
		res = info->size_a - (res + 1);
	return (res);
}

int	ft_get_bigger(int a, int b, int a_location, int b_location)
{
	int	sum1;
	int	sum2;

	sum1 = ft_abs(a) + ft_abs(b);
	sum2 = ft_abs(a_location) + ft_abs(b_location);
	if (sum1 > sum2)
		return (1);
	return (0);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			index;
	int			top;
	int			num;

	index = 0;
	top = info->size_b - 1;
	while (index < info->size_b)
	{
		num = info->stack_b[top];
		a_location = set_a_location(num, info);
		if (index >= (info->size_b + 1) / 2)
			b_location = (info->size_b - index) * -1;
		else
			b_location = index;
		if (index == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		top--;
		index++;
	}
}

void	sort_last(t_info *info)
{
	int	min;
	int	index;

	min = info->size_a - 1;
	index = info->size_a;
	while (index--)
	{
		if (info->stack_a[min] > info->stack_a[index])
			min = index;
	}
	min++;
	if (min != info->size_a)
		while (min--)
			ft_rra(info);
}

void	greedy(t_info *info)
{
	int	a;
	int	b;

	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		ft_rotate_same(info, &a, &b);
		ft_rotate_a(info, a);
		ft_rotate_b(info, b);
		ft_push_a(info);
	}
	sort_last(info);
}
