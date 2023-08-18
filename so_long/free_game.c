/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:28:21 by sgo               #+#    #+#             */
/*   Updated: 2023/08/18 14:14:20 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map(t_game *game);
void	free_img(t_game *game);

void	free_game(t_game *game)
{
	close(game->fd);
	free_map(game);
	ft_free(game->player);
	free_img(game);
	ft_free(game);
}

void	free_map(t_game *game)
{
	ft_free(game->map->line);
	ft_free(game->map);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->blank);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->col);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->player);
	ft_free(game->img);
}

void	ft_free(void *input)
{
	free (input);
	input = NULL;
}
