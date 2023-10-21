/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:26:29 by sgo               #+#    #+#             */
/*   Updated: 2023/09/28 20:33:38 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	t_arg	*arg;

	if (argc != 5)
	{
		print_err(ERR_ARG, NULL);
		return (1);
	}
	arg = init_args();
	file_open(arg, argv);
	arg->path = find_path(envp);
	do_cmd(arg, argc, argv);
	wait_all(arg, argc);
	status = arg->status;
	ft_free(arg);
	return (WEXITSTATUS(status));
}
