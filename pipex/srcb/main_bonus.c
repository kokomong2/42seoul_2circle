/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:21 by sgo               #+#    #+#             */
/*   Updated: 2023/09/27 17:12:21 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	t_arg	*arg;

	if (argc < 5 || (!ft_strcmp(argv[1], HERE_DOC) && argc < 6))
	{
		print_err(ERR_ARG, NULL);
		return (1);
	}
	arg = init_args();
	if (ft_strcmp(argv[1], HERE_DOC) == 0)
		arg->here_doc = 1;
	file_open(arg, argv);
	arg->path = find_path(envp);
	do_cmd(arg, argc, argv);
	wait_all(arg, argc);
	status = arg->status;
	ft_free(arg);
	return (WEXITSTATUS(status));
}
