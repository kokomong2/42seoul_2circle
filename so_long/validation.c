/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:31:43 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 18:40:40 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	exit_error_free(t_game *game, char *msg)
{
	write(2, "Error\n", 6);
	free_game(game);
	ft_putstr_fd(msg);
	write(1, "\n", 1);
	exit(1);
}

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(msg);
	write(1, "\n", 1);
	exit(1);
}

void	count_map(t_game *game)
{
	int		i;
	char	now;

	i = 0;
	while (game->map->line[i])
	{
		now = game->map->line[i];
		if (!(now == '0' || now == '1' || now == 'C' || now == 'E'
				|| now == 'P'))
			exit_error_free(game, MAP_ERR_MSG);
		if (now == 'C')
			game->map->collect_cnt++;
		if (now == 'P')
		{
			if (game->player->x != 0 || game->player->y != 0)
				exit_error_free(game, MAP_ERR_MSG);
			game->player->x = i % game->map->map_width;
			game->player->y = i / game->map->map_width;
			game->map->player_cnt++;
		}
		if (now == 'E')
			game->map->exit_cnt++;
		i++;
	}
	check_map(game, i);
}

void	check_map(t_game *game, int len)
{
	if (!game->map->collect_cnt)
		exit_error_free(game, MAP_ERR_MSG);
	if (game->map->exit_cnt != 1 || game->map->player_cnt != 1)
		exit_error_free(game, MAP_ERR_MSG);
	if (len != game->map->map_height * game->map->map_width)
		exit_error_free(game, MAP_ERR_MSG);
	game->win = mlx_new_window(game->mlx, game->map->win_width, game->map->win_height, "my_mlx");
}

void	check_wall(t_game *game)
{
	int	i;

	if (game->map->map_height < 3)
		exit_error_free(game, MAP_ERR_MSG);
	i = 0;
	while (i < game->map->map_width)
		if (game->map->line[i++] != '1')
			exit_error_free(game, MAP_ERR_MSG);
	while (i < game->map->map_width * (game->map->map_height - 1))
	{
		if (i % game->map->map_width == 0 || i % game->map->map_width == game->map->map_width - 1)
			if (game->map->line[i++] != '1')
				exit_error_free(game, MAP_ERR_MSG);
		i++;
	}
	while (i < game->map->map_width * game->map->map_height)
		if (game->map->line[i++] != '1')
			exit_error_free(game, MAP_ERR_MSG);
}
