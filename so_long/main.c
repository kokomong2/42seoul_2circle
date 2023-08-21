/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:40:17 by sgo               #+#    #+#             */
/*   Updated: 2023/08/21 20:56:35 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	(void)argv;
	if (argc != 2)
		exit_error(ARG_ERR_MSG);
	game = init_game(argv[1]);
	copymap(game);
	count_map(game);
	check_wall(game);
	check_dfs(game);
	drawmap(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
