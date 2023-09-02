/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:23:14 by sgo               #+#    #+#             */
/*   Updated: 2023/09/02 19:14:38 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_arg	*init_args()
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->path = NULL;
	arg->cmd = NULL;
	arg->cmd_args = NULL;
	arg->pipe_fd[0] = 0;
	arg->pipe_fd[1] = 1;
	arg->tmp_fd = 0;
	arg->outfile_fd = 0;
	arg->pid = 0;
	return (arg);
}
