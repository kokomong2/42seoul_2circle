/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:26:38 by sgo               #+#    #+#             */
/*   Updated: 2023/08/18 13:18:29 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_left(t_game *game, int x, int y);
static void	move_right(t_game *game, int x, int y);
static void	move_up(t_game *game, int x, int y);
static void	move_down(t_game *game, int x, int y);

int	key_press(int keycode, t_game *game)
{
	printf("x : %d, y : %d\n", game->player->x, game->player->y);
	printf("move : %d\n", game->player->move_cnt);
	if (keycode == KEY_W)
		move_up(game, game->player->x, game->player->y);
	else if (keycode == KEY_S)
		move_down(game, game->player->x, game->player->y);
	else if (keycode == KEY_A)
		move_left(game, game->player->x, game->player->y);
	else if (keycode == KEY_D)
		move_right(game, game->player->x, game->player->y);
	else if (keycode == KEY_ESC)
		exit_game(game);
	drawmap(game);
	return (0);
}

static void	move_left(t_game *game, int x, int y)
{
	char	*line;

	x = y * game->map->wid + x;
	line = game->map->line;
	if (line[x - 1] == '1')
		return ;
	else if (line[x - 1] == 'C')
		game->map->collect_cnt--;
	else if (line[x - 1] == 'E')
	{
		if (game->map->collect_cnt == 0)
			exit_game(game);
		return ;
	}
	game->map->line[x - 1] = 'P';
	game->map->line[x] = '0';
	game->player->x--;
	game->player->move_cnt++;
}

static void	move_right(t_game *game, int x, int y)
{
	char	*line;

	x = y * game->map->wid + x;
	line = game->map->line;
	if (line[x + 1] == '1')
		return ;
	else if (line[x + 1] == 'C')
		game->map->collect_cnt--;
	else if (line[x + 1] == 'E')
	{
		if (game->map->collect_cnt == 0)
			exit_game(game);
		return ;
	}
	game->map->line[x + 1] = 'P';
	game->map->line[x] = '0';
	game->player->x++;
	game->player->move_cnt++;
}

static void	move_up(t_game *game, int x, int y)
{
	char	*line;

	x = y * game->map->wid + x;
	line = game->map->line;
	if (line[x - game->map->wid] == '1')
		return ;
	else if (line[x - game->map->wid] == 'C')
		game->map->collect_cnt--;
	else if (line[x - game->map->wid] == 'E')
	{
		if (game->map->collect_cnt == 0)
			exit_game(game);
		return ;
	}
	game->map->line[x - game->map->wid] = 'P';
	game->map->line[x] = '0';
	game->player->y--;
	game->player->move_cnt++;
}

static void	move_down(t_game *game, int x, int y)
{
	char	*line;

	x = y * game->map->wid + x;
	line = game->map->line;
	if (line[x + game->map->wid] == '1')
		return ;
	else if (line[x + game->map->wid] == 'C')
		game->map->collect_cnt--;
	else if (line[x + game->map->wid] == 'E')
	{
		if (game->map->collect_cnt == 0)
			exit_game(game);
		return ;
	}
	game->map->line[x + game->map->wid] = 'P';
	game->map->line[x] = '0';
	game->player->y++;
	game->player->move_cnt++;
}
