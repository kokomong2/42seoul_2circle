/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:50:18 by sgo               #+#    #+#             */
/*   Updated: 2023/09/20 22:32:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
