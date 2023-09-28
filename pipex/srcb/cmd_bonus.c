/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:41:35 by sgo               #+#    #+#             */
/*   Updated: 2023/09/27 17:31:54 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	check_slash(char *cmd);

char	*get_cmd(char	**path, char *cmd)
{
	int		index;
	char	*path_cmd;
	char	*tmp;

	if (cmd == NULL || path == NULL)
		return (NULL);
	path_cmd = ft_strjoin("/", cmd);
	index = 0;
	while (path[index])
	{
		if (check_slash(cmd))
			tmp = ft_strdup(cmd);
		else
			tmp = ft_strjoin(path[index], path_cmd);
		if (access(tmp, X_OK) != -1)
		{
			free (path_cmd);
			return (tmp);
		}
		ft_free(tmp);
		index++;
	}
	ft_free(path_cmd);
	return (NULL);
}

void	do_cmd(t_arg *arg, int argc, char *argv[], char **envp)
{
	int	i;

	i = 2;
	if (arg->here_doc)
		i = 3;
	while (i < argc - 1)
	{
		if (pipe(arg->pipe_fd) == -1)
			exit_perror(ERROR, arg);
		arg->cmd_args = ft_split(argv[i], ' ');
		if (arg->cmd_args == NULL)
			exit_perror(ERROR, arg);
		arg->pid = fork();
		if (arg->pid < 0)
			exit_perror(ERROR, arg);
		get_child(arg, i, argc, envp);
		free_double_arr(arg->cmd_args);
		ft_free(arg->cmd);
		i++;
	}
	free_double_arr(arg->path);
}

int	check_slash(char *cmd)
{
	if (ft_strncmp(cmd, "/", 1) == 0
		|| ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		return (1);
	}
	return (0);
}
