/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:02 by sgo               #+#    #+#             */
/*   Updated: 2023/07/29 20:41:52 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_str_size(int argc, char *argv[])
{
	int		len;
	int		i;
	int		j;
	char	**arr;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		if (is_all_blank(argv[i]))
			print_error();
		arr = ft_split(argv[i], ' ');
		if (!arr)
			exit(1);
		while (arr[j])
		{
			len++;
			j++;
		}
		i++;
		freeresult(j, arr);
	}
	return (len);
}

void	ft_argv_to_array(char *argv[], int array_size, t_info *info)
{
	int		i;
	int		j;
	char	**arr;
	int		tmp;

	if (array_size <= 0)
		print_error();
	i = array_size - 1;
	while (i >= 0)
	{
		j = 0;
		arr = ft_split(*argv, ' ');
		if (!arr)
			exit(1);
		argv++;
		while (arr[j])
		{
			tmp = ft_atoi(arr[j++]);
			check_duplicate(info, info->array, array_size, tmp);
			info->array[i] = tmp;
			info->stack_a[i] = info->array[i];
			i--;
		}
		freeresult(j, arr);
	}
}

void	array_sort(t_info *info, int array_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	if (array_size < 2)
		return ;
	while (i < array_size)
	{
		j = 1;
		while (j < array_size)
		{
			if (info->array[j] < info->array[j - 1])
			{
				tmp = info->array[j];
				info->array[j] = info->array[j - 1];
				info->array[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	binary_search(t_info *info, int index, int low, int high)
{
	int	mid;

	if (low > high)
		return ;
	mid = (low + high) / 2;
	if (info->array[mid] == info->stack_a[index])
	{
		info->stack_a[index] = mid;
		return ;
	}
	else if (info->array[mid] > info->stack_a[index])
		return (binary_search(info, index, low, mid - 1));
	else
		return (binary_search(info, index, mid + 1, high));
}

void	check_sorted(t_info *info, int array_size)
{
	int	i;

	i = 0;
	if (array_size < 2)
		exit(0);
	while (i < array_size - 1)
	{
		if (info->array[i] < info->array[i + 1])
			return ;
		i++;
	}
	exit(0);
}
