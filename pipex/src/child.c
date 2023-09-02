/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:57:47 by sgo               #+#    #+#             */
/*   Updated: 2023/09/02 20:08:41 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_child(t_arg *arg, int i, int argc, char **envp)
{
	printf("get_child\n");
	arg->pid = fork();
	if (arg->pid < 0)
		exit_error();
	if (arg->pid == 0)
	{
		dup2(arg->tmp_fd, STDIN_FILENO);
		if (i == argc - 2)
			dup2(arg->outfile_fd, STDOUT_FILENO);
		else
			dup2(arg->pipe_fd[1], STDOUT_FILENO);
		close(arg->pipe_fd[1]);
		close(arg->tmp_fd);
		execve(arg->cmd, arg->cmd_args, envp);
	}
	else
	{
		close(arg->tmp_fd);
		arg->tmp_fd = dup(arg->pipe_fd[0]);
		close(arg->pipe_fd[0]);
		close(arg->pipe_fd[1]);
		waitpid(arg->pid, NULL, 0);
	}
}
