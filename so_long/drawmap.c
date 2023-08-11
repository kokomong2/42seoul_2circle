/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:04:47 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 15:01:48 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

void	draw_img(char now, t_game *game,int x, int y)
{
	// printf("now : %c\n", now);
	mlx_put_image_to_window(game->mlx, game->win, game->img->blank, x, y);
	if (now == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, x, y);
	if (now == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, x, y);
	if (now == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img->collection, x, y);
	if (now == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, x, y);
}

void	drawmap(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx_clear_window(game->mlx, game->win);
	while (game->map->line[i])
	{
		x = i % game->map->map_width * game->bit;
		y = i / game->map->map_width * game->bit;
		draw_img(game->map->line[i], game, x, y);
		i++;
	}
}