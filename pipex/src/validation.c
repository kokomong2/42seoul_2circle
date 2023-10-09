/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:04:59 by sgo               #+#    #+#             */
/*   Updated: 2023/09/28 23:37:58 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_perror(char *msg, t_arg *arg)
{
	free_args(arg);
	perror(msg);
	exit(1);
}

void	print_err(char *msg, char *str)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
}

void	exit_cmd_err(char *msg, char *str)
{
	print_err(msg, str);
	exit(127);
}

void	exit_free(t_arg *arg)
{
	close(arg->tmp_fd);
	close(arg->pipe_fd[1]);
	close(arg->pipe_fd[0]);
	free_args(arg);
	exit(1);
}
