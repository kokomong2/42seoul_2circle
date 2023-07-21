/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:12 by sgo               #+#    #+#             */
/*   Updated: 2023/07/21 16:41:46 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate_same(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b >0))
	{
		ft_rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		ft_rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}
void	ft_rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ft_ra(info);
			a--;
		}
		else
		{
			ft_rra(info);
			a++;
		}
	}
}
void	ft_rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			ft_rb(info);
			b--;
		}
		else
		{
			ft_rrb(info);
			b++;
		}
	}
}

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}