/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:28:21 by sgo               #+#    #+#             */
/*   Updated: 2023/08/14 19:04:59 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map(t_game *game);
void	free_img(t_game *game);

void	free_game(t_game *game)
{
	close(game->fd);
	free_map(game);
	free(game->player);
	game->player = NULL;
	free_img(game);
	free(game);
	game = NULL;
}

void	free_map(t_game *game)
{
	free(game->map->line);
	game->map->line = NULL;
	free(game->map);
	game->map = NULL;
}

void	free_img(t_game *game)
{
	free(game->img->blank);
	game->img->blank = NULL;
	free(game->img->wall);
	game->img->wall = NULL;
	free(game->img->col);
	game->img->col = NULL;
	free(game->img->exit);
	game->img->exit = NULL;
	free(game->img->player);
	game->img->player = NULL;
	free(game->img);
	game->img = NULL;
}
