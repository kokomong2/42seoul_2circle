/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:02 by sgo               #+#    #+#             */
/*   Updated: 2023/07/14 19:49:05 by sgo              ###   ########.fr       */
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
		arr = ft_split(argv[i], ' ');
		if (!arr)
			return (0);
		while (arr[j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

int	*ft_argv_to_array(char *argv[], int array_size)
{
	int		*array;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	array = (int *)malloc(sizeof(int) * array_size);
	if (!array)
		exit(1);
	argv++;
	while (i < array_size)
	{
		j = 0;
		arr = ft_split(*argv, ' ');
		if (!arr)
			exit(1);
		argv++;
		while (arr[j])
			array[i++] = ft_atoi(arr[j++]);
	}
	return (array);
}

void	ft_arr_to_stack(t_info *info,int *num_array, int array_size)
{
	int	i;

	i = 0;
	if (!num_array || array_size < 0)
		return ;
	info->bottom_a = ft_newstack(num_array[i]);
	info->size_a++;
	if (array_size > 1)
	{
		info->top_a = ft_push(&(info->bottom_a), num_array[++i]);
		info->size_a++;
		while (i < array_size - 1)
		{
			info->top_a = ft_push(&(info->top_a), num_array[++i]);
			info->size_a++;
		}
	}
}
