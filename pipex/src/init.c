/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:23:14 by sgo               #+#    #+#             */
/*   Updated: 2023/10/05 22:29:47 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_args(t_arg *arg)
{
	if (!arg)
		exit(1);
	arg->path = NULL;
	arg->cmd = NULL;
	arg->cmd_args = NULL;
	arg->pipe_fd[0] = 0;
	arg->pipe_fd[1] = 1;
	arg->tmp_fd = 0;
	arg->outfile_fd = 0;
	arg->pid = 0;
	arg->status = 0;
	return (arg);
}
