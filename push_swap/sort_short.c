/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:44:34 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 18:27:02 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_short(t_info *info)
{
	int	top;
	int	bottom;

	bottom = info->size_a;
	while (info->size_a > 3)
	{
		top = info->stack_a[info->size_a - 1];
		if (top < bottom && top >= bottom - 3)
			ft_ra(info);
		else
			ft_push_b(info);
	}
}
