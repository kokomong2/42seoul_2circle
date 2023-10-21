/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:30 by sgo               #+#    #+#             */
/*   Updated: 2023/09/27 17:30:57 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# define ERROR "Error"
# define ERR_CMD ": command not found"
# define FILE_NAME_ERR ": no such file or directory"
# define ERR_ARG "인자수가 맞지 않음"
# define DUP_ERR "dup_error"
# define FD_ERR "fd_error"
# define EXE_ERR "exe_error"

typedef struct s_arg
{
	char	**path;
	char	*cmd;
	char	**cmd_args;
	int		pipe_fd[2];
	int		tmp_fd;
	int		outfile_fd;
	pid_t	pid;
	int		status;
}			t_arg;

char	**find_path(char **envp);
char	*get_cmd(char	**path, char *cmd);
t_arg	*init_args(void);
void	exit_perror(char *msg, t_arg *arg);
void	exit_cmd_err(char *msg, char *str);
void	print_err(char *msg, char *str);
void	file_open(t_arg *arg, char *argv[]);
void	get_child(t_arg *arg, int i, int argc, char *argv[]);
void	do_cmd(t_arg *arg, int argc, char *argv[]);
void	free_args(t_arg *arg);
void	ft_free(void *arr);
void	exit_free(t_arg *arg);
void	wait_all(t_arg *arg, int argc);
void	free_double_arr(char **arr);
void	dup_stdout(t_arg *arg, int i, int argc, char *argv[]);

#endif