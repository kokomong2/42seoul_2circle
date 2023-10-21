/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:31 by sgo               #+#    #+#             */
/*   Updated: 2023/09/17 21:50:22 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	free_double_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}

void	free_args(t_arg *arg)
{
	if (arg->path != NULL)
		free_double_arr(arg->path);
	if (arg->cmd != NULL)
		ft_free(arg->cmd);
	if (arg->cmd_args != NULL)
		free_double_arr(arg->cmd_args);
	ft_free(arg);
}

void	ft_free(void *arr)
{
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}
