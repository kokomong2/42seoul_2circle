/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:31:43 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:01:07 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	exit_error_free(t_game *game, char *msg)
{
	write(2, "Error\n", 6);
	(void)game;
	// free_game(game);
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

void	check_map(t_game *game)
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
		}
		i++;
	}
	if (i != game->map->map_height * game->map->map_width)
		exit_error_free(game, MAP_ERR_MSG);
	game->win = mlx_new_window(game->mlx, game->map->win_width,
			game->map->win_height, "my_mlx");
}
