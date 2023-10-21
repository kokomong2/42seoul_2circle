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

void	file_open(t_arg *arg, char *argv[])
{
	if (arg->here_doc)
	{
		here_doc(arg, argv[2]);
		arg->tmp_fd = open(HERE_DOC_FILE, O_RDONLY);
		if (arg->tmp_fd < 0)
			perror(HERE_DOC_FILE);
	}
	else
	{
		arg->tmp_fd = open(argv[1], O_RDONLY);
		if (arg->tmp_fd < 0)
			perror(argv[1]);
	}
}
