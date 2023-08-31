/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:26:29 by sgo               #+#    #+#             */
/*   Updated: 2023/08/31 16:58:27 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		i;
	char	**path;
	char	*res;
	
	(void)argv;
	(void)argc;
	i = 0;
	path = find_path(envp);
	if (!path)
		exit(1);
	res = get_cmd(path, argv[1]);
	printf("res : %s\n", res);
}
