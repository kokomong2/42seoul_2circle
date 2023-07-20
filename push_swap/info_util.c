/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:29:10 by sgo               #+#    #+#             */
/*   Updated: 2023/07/19 19:04:36 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info	*ft_info_new(int size)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	new -> array = (int *)malloc(sizeof(int) * size);
	new -> stack_a =(int *)malloc(sizeof(int) * size);
	new -> bottom_index_a = 0;
	new -> top_index_a = 0;
	new -> stack_b = (int *)malloc(sizeof(int) * size);
	new -> bottom_index_b = 0;
	new -> top_index_b = 0;
	//malloc실패를 한번에 처리하는것인데 만약 잘못될경우 수정
	if (!new || !new->array || !new->stack_a || !new->stack_b)
		exit(1);
	return (new);
}