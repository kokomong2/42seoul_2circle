/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:06:16 by sgo               #+#    #+#             */
/*   Updated: 2023/08/21 20:58:14 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_xy(t_xy *xy, int dx, int dy, int i);
static t_xy	*get_start_xy(t_game *game, int *visited);

void	dfs(t_game *game, int *visited, int *cnt, t_xy *xy)
{
	int	index;
	int	dx;
	int	dy;
	int	i;

	dx = xy->x;
	dy = xy->y;
	i = 0;
	index = xy->y * game->map->wid + xy->x;
	if (game->map->line[index] == 'E')
	{
		xy->is_exit = 1;
		return ;
	}
	if (game->map->line[index] == 'C')
		*cnt = *cnt + 1;
	while (i < 4)
	{
		move_xy(xy, dx, dy, i++);
		index = xy->y * game->map->wid + xy->x;
		if (game->map->line[index] == '1' || visited[index] == 1)
			continue ;
		visited[xy->y * game->map->wid + xy->x] = 1;
		dfs(game, visited, cnt, xy);
	}
}

static void	move_xy(t_xy *xy, int dx, int dy, int i)
{
	if (i == 0)
	{
		xy->x = dx + 1;
		xy->y = dy;
	}
	if (i == 1)
	{
		xy->x = dx - 1;
		xy->y = dy;
	}
	if (i == 2)
	{
		xy->x = dx;
		xy->y = dy + 1;
	}
	if (i == 3)
	{
		xy->x = dx;
		xy->y = dy - 1;
	}
}

void	check_dfs(t_game *game)
{
	int		*visited;
	int		len;
	int		i;
	t_xy	*xy;
	int		cnt;

	i = 0;
	cnt = 0;
	len = get_strlen(game->map->line);
	visited = (int *)malloc(sizeof(int) * len);
	if (!visited)
		exit_error_free(game, MALLOC_ERR);
	xy = get_start_xy(game, visited);
	while (i < len)
		visited[i++] = 0;
	visited[xy->y * game->map->wid + xy->x] = 1;
	dfs(game, visited, &cnt, xy);
	i = xy->is_exit;
	free(xy);
	free(visited);
	if (cnt != game->map->collect_cnt || i != 1)
		exit_error_free(game, MAP_CANT_EXIT);
}

static t_xy	*get_start_xy(t_game *game, int *visited)
{
	t_xy	*xy;

	xy = (t_xy *)malloc(sizeof(t_xy));
	xy->x = game->player->x;
	xy->y = game->player->y;
	xy->is_exit = 0;
	if (!xy)
	{
		ft_free(visited);
		exit_error_free(game, MALLOC_ERR);
	}
	return (xy);
}
