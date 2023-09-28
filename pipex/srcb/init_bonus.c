/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:26 by sgo               #+#    #+#             */
/*   Updated: 2023/09/20 20:29:35 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_arg	*init_args(void)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
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
	arg->here_doc = 0;
	return (arg);
}
