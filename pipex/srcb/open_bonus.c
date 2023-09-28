/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:16 by sgo               #+#    #+#             */
/*   Updated: 2023/09/25 17:30:36 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	file_open(t_arg *arg, int argc, char *argv[])
{
	if (arg->here_doc)
	{
		here_doc(arg, argv[2]);
		arg->tmp_fd = open(HERE_DOC_FILE, O_RDONLY);
		if (arg->tmp_fd < 0)
			perror(HERE_DOC_FILE);
		arg->outfile_fd = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		arg->tmp_fd = open(argv[1], O_RDONLY);
		if (arg->tmp_fd < 0)
			perror(argv[1]);
		arg->outfile_fd = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (arg->outfile_fd < 0)
		exit_perror(argv[argc - 1], arg);
}
