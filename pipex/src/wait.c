/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:08:49 by sgo               #+#    #+#             */
/*   Updated: 2023/09/27 17:09:05 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	wait_all(t_arg *arg, int argc)
{
	int	count;

	count = 0;
	waitpid(arg->pid, &arg->status, 0);
	while (count < argc - 4)
	{
		if (wait(0) == -1)
			exit(1);
		count++;
	}
}
