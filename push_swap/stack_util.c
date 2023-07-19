/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:29 by sgo               #+#    #+#             */
/*   Updated: 2023/07/14 18:25:34 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_newstack(int content)
{
	t_stack	*newlst;

	newlst = (t_stack *)malloc(sizeof(t_stack));
	if (!newlst)
		exit(1);
	newlst -> content = content;
	newlst -> next = NULL;
	newlst -> prev = NULL;
	return (newlst);
}

t_stack	*ft_push(t_stack **stack, int content)
{
	t_stack	*new;

	new = ft_newstack(content);
	(*stack)->next = new;
	new->prev = (*stack);
	return (new);
}