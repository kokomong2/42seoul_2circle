/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:31:43 by sgo               #+#    #+#             */
/*   Updated: 2023/08/18 17:16:09 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	exit_error_free(t_game *game, char *msg)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	free_game(game);
	exit(1);
}

void	exit_error(char *msg)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	exit(1);
}

void	count_map(t_game *game)
{
	int		i;
	char	c;

	i = 0;
	while (game->map->line[i])
	{
		c = game->map->line[i];
		if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
			exit_error_free(game, MAP_ERR_MSG);
		if (c == 'C')
			game->map->collect_cnt++;
		if (c == 'P')
		{
			if (game->player->x != 0 || game->player->y != 0)
				exit_error_free(game, MAP_DUP_ERR);
			game->player->x = i % game->map->wid;
			game->player->y = i / game->map->wid;
			game->map->player_cnt++;
		}
		if (c == 'E')
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
		exit_error_free(game, MAP_DUP_ERR);
	if (len != game->map->hei * game->map->wid)
		exit_error_free(game, MAP_REC_ERR);
	game->win = \
	mlx_new_window(game->mlx, game->map->win_wid, game->map->win_hei, "my_mlx");
}

void	check_wall(t_game *game)
{
	int	i;

	if (game->map->hei < 3)
		exit_error_free(game, MAP_ERR_MSG);
	i = 0;
	while (i < game->map->wid)
		if (game->map->line[i++] != '1')
			exit_error_free(game, MAP_WALL_ERR);
	while (i < game->map->wid * (game->map->hei - 1))
	{
		if (i % game->map->wid == 0 || i % game->map->wid == game->map->wid - 1)
			if (game->map->line[i++] != '1')
				exit_error_free(game, MAP_WALL_ERR);
		i++;
	}
	while (i < game->map->wid * game->map->hei)
		if (game->map->line[i++] != '1')
			exit_error_free(game, MAP_WALL_ERR);
}
