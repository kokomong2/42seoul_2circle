/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:40:17 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:09:29 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

void	foo(void)
{
	system("leaks so_long");
}

int main(int argc, char *argv[])
{
	t_game	*game;
	
	(void)argv;
	if (argc != 2)
		exit_error(ARG_ERR_MSG);
	// atexit(foo);
	game = init_game(argv[1]);
	copymap(game);
	check_map(game);
	drawmap(game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(game->mlx);
	// free_game(game);
	return (0);
}
