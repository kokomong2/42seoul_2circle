/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:26:29 by sgo               #+#    #+#             */
/*   Updated: 2023/09/02 20:03:21 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		i;
	t_arg	*arg;
	
	(void)argc;
	arg = init_args();
	i = 2;
	file_open(arg, argc, argv);
	arg->path = find_path(envp);
	if (arg->path == NULL)
		exit_error();
	if (pipe(arg->pipe_fd) == -1)
		exit_error();
	while (i < argc - 1)
	{
		arg->cmd_args = ft_split(argv[i], ' ');
		if (arg->cmd_args == NULL)
			exit_error();
		arg->cmd = get_cmd(arg->path, arg->cmd_args[0]);
		if (arg->cmd == NULL)
			exit_error();
		printf("cmd : %s\n", arg->cmd);
		get_child(arg, i, argc, envp);
		i++;
	}
}
