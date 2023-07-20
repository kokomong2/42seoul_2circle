/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:05:00 by sgo               #+#    #+#             */
/*   Updated: 2023/07/19 20:13:23 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char* argv[])
{
	int		array_size;
	t_info	*info;

	(void)argv;
	if (argc < 2)
		print_error(-1);
	array_size = get_str_size(argc, argv);
	info = ft_info_new(array_size);
	ft_argv_to_array(argv, array_size, info);
	print_stack(info);
	ft_reverse_a(info);
	print_stack(info);
}

//test
void print_stack(t_info *info)
{
	printf("stack A\n");
	for(int i = info->bottom_index_a; i < info->top_index_a; i++)
	{
		int now = info->stack_a[i];
		printf("%d ",now);
	}
	printf("\n");
	printf("stack B\n");
	for(int i = info->bottom_index_b; i < info->top_index_b; i++)
	{
		int now = info->array[info->stack_b[i]];
		printf("%d ",now);
	}
	printf("\n");
}
//test

void print_error(int type)
{
	if (type > 0){
		write(1,"Error\n", 6);
	}
	exit(1);
}