/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:30 by sgo               #+#    #+#             */
/*   Updated: 2023/09/02 20:00:09 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# define ERROR "Error"
# define ERR_COM "잘못된 명령어 입니다."

typedef struct s_arg
{
	char	**path;
	char	*cmd;
	char	**cmd_args;
	int		pipe_fd[2];
	int		tmp_fd;
	int		outfile_fd;
	int		pid;
}			t_arg;

char	**find_path(char **envp);
char	*get_cmd(char	**path, char *cmd);
t_arg	*init_args();
void	exit_error();
void	file_open(t_arg *arg, int argc, char *argv[]);
void	get_child(t_arg *arg, int i, int argc, char **envp);

#endif