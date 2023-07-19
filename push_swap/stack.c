/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:27:31 by sgo               #+#    #+#             */
/*   Updated: 2023/07/17 20:02:45 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_a(t_info *info)
{
	t_stack	*tmp;

	if (info -> size_a < 2)
		return ;
	tmp = info->top_a->prev;
	info->top_a->prev = info->top_a->prev->prev;
	tmp->prev->next = info->top_a;
	info->top_a->next = tmp;
	tmp->prev = info->top_a;
	info->top_a = tmp;
}