/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:10 by sgo               #+#    #+#             */
/*   Updated: 2023/09/17 21:50:33 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**find_path(char **envp)
{
	int		index;
	char	*ret_path;
	char	**res;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp("PATH=", envp[index], 5) == 0)
		{
			ret_path = ft_strdup(envp[index] + 5);
			res = ft_split(ret_path, ':');
			ft_free(ret_path);
			return (res);
		}
		index++;
	}
	return (0);
}
