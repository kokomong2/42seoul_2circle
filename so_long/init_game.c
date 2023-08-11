/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:38:19 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 18:34:15 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

static void	read_file(t_game *game, char *file);
static void	init_map(t_game *game);
static void	init_player(t_game *game);
static void	init_img(t_game *game);

t_game	*init_game(char *file)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit(1);
	read_file(game, file);
	init_map(game);
	game->win = NULL;
	game->mlx = mlx_init();
	game->bit = 32;
	init_player(game);
	init_img(game);
	return (game);
}

static void	read_file(t_game *game, char *file)
{
	char	*mapname;
	
	mapname = ft_strdup(MAP_ROUTE);
	if (!mapname)
		exit(1);
	mapname = ft_strjoin(mapname, file, get_strlen(file));
	if (!mapname)
		exit(1);
	game->fd = open(mapname, O_RDONLY);
	if (game->fd <= 0)
		exit_error(FILENAME_ERR_MSG);
	free(mapname);
	mapname = NULL;
}

static void	init_map(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		exit(1);
	game->map->line = NULL;
	game->map->win_height = 0;
	game->map->win_width = 0;
	game->map->map_height = 0;
	game->map->map_width = 0;
	game->map->collect_cnt = 0;
	game->map->exit_cnt = 0;
	game->map->player_cnt = 0;
}

static void	init_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		exit(1);
	game->player->x = 0;
	game->player->y = 0;
	game->player->move_cnt = 0;
}

static void	init_img(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		exit(1);
	game->img->blank = mlx_xpm_file_to_image(game->mlx, "./images/road_tile2.xpm", &game->img->img_wi, &game->img->img_he);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "./images/wall_tile.xpm", &game->img->img_wi, &game->img->img_he);
	game->img->collection = mlx_xpm_file_to_image(game->mlx, "./images/coll2.xpm", &game->img->img_wi, &game->img->img_he);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "./images/road_tile2.xpm", &game->img->img_wi, &game->img->img_he);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "./images/char1.xpm", &game->img->img_wi, &game->img->img_he);

}
