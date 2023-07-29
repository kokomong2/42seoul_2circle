/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:05:00 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 17:08:25 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	int		array_size;
	t_info	*info;

	if (argc < 2)
		return (0);
	array_size = get_str_size(argc, argv);
	info = ft_info_new(array_size);
	ft_argv_to_array(++argv, array_size, info);
	check_sorted(info, array_size);
	array_sort(info, array_size);
	indexing_stack_a(info);
	if (array_size < 10)
		sort_short(info);
	else
		get_pivot(info, array_size);
	sort_three(info);
	greedy(info);
	return (0);
}
