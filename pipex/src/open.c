/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:28:29 by sgo               #+#    #+#             */
/*   Updated: 2023/09/26 19:47:50 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	file_open(t_arg *arg, int argc, char *argv[])
{
	arg->tmp_fd = open(argv[1], O_RDONLY);
	if (arg->tmp_fd < 0)
		perror(argv[1]);
	arg->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile_fd < 0)
		exit_perror(argv[argc - 1], arg);
}
