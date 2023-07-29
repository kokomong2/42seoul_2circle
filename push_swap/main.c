/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:05:00 by sgo               #+#    #+#             */
/*   Updated: 2023/07/27 20:38:23 by sgo              ###   ########.fr       */
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
	ft_argv_to_array(argv, array_size, info);
	check_sorted(info, array_size);
	array_sort(info, array_size);
	// print_array(info, array_size);
	indexing_stack_a(info);
	if (array_size < 10)
		sort_short(info);
	else
		get_pivot(info, array_size);
	sort_three(info);
	greedy(info);
	return (0);
}

//test
void	print_stack(t_info *info)
{
	printf("stack A\n");
	for(int i = info->top_index_a - 1; i >= info->bottom_index_a; i--)
	{
		int now = info->stack_a[i];
		printf("%d ",now);
	}
	printf("\n");
	printf("stack B\n");
	for(int i = info->top_index_b - 1; i >= info->bottom_index_b; i--)
	{
		int now = info->stack_b[i];
		printf("%d ",now);
	}
	printf("\n");
}

void print_array(t_info *info, int array_size)
{
	printf("array\n");
	for (int i = 0; i < array_size; i++)
		printf("%d ", info->array[i]);
	printf("\n");
}
//test