/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:57:47 by sgo               #+#    #+#             */
/*   Updated: 2023/09/27 20:12:57 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_child(t_arg *arg, int i, int argc, char **envp)
{
	if (arg->pid == 0)
	{
		close(arg->pipe_fd[0]);
		dup_stdout(arg, i, argc);
		if (dup2(arg->tmp_fd, STDIN_FILENO) == -1)
			exit_perror(DUP_ERR, arg);
		close(arg->tmp_fd);
		if (arg->tmp_fd < 0)
			exit_free(arg);
		if (arg->path == NULL)
			exit_cmd_err(arg->cmd_args[0], FILE_NAME_ERR);
		arg->cmd = get_cmd(arg->path, arg->cmd_args[0]);
		if (arg->cmd == NULL)
			exit_cmd_err(arg->cmd_args[0], ERR_CMD);
		if (execve(arg->cmd, arg->cmd_args, envp) == -1)
			exit_perror(EXE_ERR, arg);
	}
	close(arg->tmp_fd);
	arg->tmp_fd = dup(arg->pipe_fd[0]);
	if (arg->tmp_fd == -1)
		perror(FD_ERR);
	close(arg->pipe_fd[0]);
	close(arg->pipe_fd[1]);
}

void	dup_stdout(t_arg *arg, int i, int argc)
{
	if (i == argc - 2)
	{
		close(arg->pipe_fd[1]);
		if (dup2(arg->outfile_fd, STDOUT_FILENO) == -1)
			exit_perror(DUP_ERR, arg);
	}
	else
	{
		if (dup2(arg->pipe_fd[1], STDOUT_FILENO) == -1)
			exit_perror(DUP_ERR, arg);
	}
}
