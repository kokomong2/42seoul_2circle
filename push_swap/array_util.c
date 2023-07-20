/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:02 by sgo               #+#    #+#             */
/*   Updated: 2023/07/19 21:03:13 by sgo              ###   ########.fr       */
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

void	ft_argv_to_array(char *argv[], int array_size, t_info	*info)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	argv++;
	while (i < array_size)
	{
		j = 0;
		arr = ft_split(*argv, ' ');
		if (!arr)
			exit(1);
		argv++;
		while (arr[j]){
			info->array[i] = ft_atoi(arr[j++]);
			info->stack_a[i] = info->array[i];
			info->top_index_a++;
			i++;
		}
	}
}
