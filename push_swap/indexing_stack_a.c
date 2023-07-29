/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:35:49 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 16:08:53 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	indexing_stack_a(t_info *info)
{
	int	i;

	i = info->bottom_index_a;
	while (i < info->size_a)
	{
		binary_search(info, i, info->bottom_index_a, info->size_a);
		i++;
	}
}
