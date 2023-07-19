/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:29:10 by sgo               #+#    #+#             */
/*   Updated: 2023/07/14 16:25:40 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info	*ft_info_new()
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	new -> array = NULL;
	new -> size_a = 0;
	new -> top_a = NULL;
	new -> bottom_a = NULL;
	new -> size_b = 0;
	new -> top_b = NULL;
	new -> bottom_b = NULL;
	return (new);
}