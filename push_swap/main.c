/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:05:00 by sgo               #+#    #+#             */
/*   Updated: 2023/07/14 20:06:36 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char* argv[])
{
	int		array_size;
	int		*num_array;
	t_info	*info;

	(void)argv;
	if (argc < 2)
		print_error(-1);
	array_size = 0;
	info = ft_info_new();
	array_size = get_str_size(argc, argv);
	num_array = ft_argv_to_array(argv, array_size);
	ft_arr_to_stack(info, num_array, array_size);
	print_stack(info);
	ft_swap_a(info);
	print_stack(info);
}

//test
void print_stack(t_info *info)
{
	t_stack *tmpa;
	printf("stack A\n");
	tmpa = info->bottom_a;
	for(int i = 0; i < info->size_a; i++)
	{
		int now = tmpa->content;
		printf("%d ",now);
		tmpa = tmpa->next;
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