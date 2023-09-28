/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:29:10 by sgo               #+#    #+#             */
/*   Updated: 2023/07/31 19:14:29 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info	*ft_info_new(int size)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		exit(1);
	new->array = (int *)malloc(sizeof(int) * size);
	new->stack_a = (int *)malloc(sizeof(int) * size);
	new->size_a = size;
	new->bottom_index_a = 0;
	new->stack_b = (int *)malloc(sizeof(int) * size);
	new->bottom_index_b = 0;
	new->size_b = 0;
	new->have_zero = 0;
	if (!new->array || !new->stack_a || !new->stack_b)
		exit(1);
	return (new);
}

void	free_info(t_info *info)
{
	free(info->array);
	info->array = NULL;
	free(info->stack_a);
	info->array = NULL;
	free(info->stack_b);
	info->array = NULL;
	free(info);
}
