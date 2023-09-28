/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:15:33 by sgo               #+#    #+#             */
/*   Updated: 2023/09/26 17:44:54 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	here_doc(t_arg *arg, char *argv)
{
	int		file;
	char	*line;

	unlink(HERE_DOC_FILE);
	file = open(HERE_DOC_FILE, O_CREAT | O_WRONLY | O_TRUNC, 00000644);
	if (file < 0)
		exit_perror(ERROR, arg);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			exit_perror(ERROR, arg);
		if (ft_strncmp(argv, line, ft_strlen(argv)) == 0 && \
			ft_strlen(argv) == (ft_strlen(line) - 1))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	if (close(file) == -1)
		exit_perror(FD_ERR, arg);
}
