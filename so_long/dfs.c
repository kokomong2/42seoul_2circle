/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:06:16 by sgo               #+#    #+#             */
/*   Updated: 2023/08/14 19:20:14 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_xy(t_xy *xy, int dx, int dy, int i);

int	dfs(t_game *game, int *visited, int cnt, t_xy *xy)
{
	int	index;
	int	dx;
	int	dy;
	int	i;

	dx = xy->x;
	dy = xy->y;
	i = 0;
	index = xy->y * game->map->wid + xy->x;
	if (game->map->line[index] == 'E' && cnt == 0)
		return (1);
	if (game->map->line[index] == 'C')
		cnt--;
	while (i < 4)
	{
		move_xy(xy, dx, dy, i++);
		index = xy->y * game->map->wid + xy->x;
		if (game->map->line[index] == '1' || visited[index] == 1)
			continue ;
		visited[xy->y * game->map->wid + xy->x] = 1;
		if (dfs(game, visited, cnt, xy))
			return (1);
		visited[xy->y * game->map->wid + xy->x] = 0;
	}
	return (0);
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

	i = 0;
	len = get_strlen(game->map->line);
	visited = (int *)malloc(sizeof(int) * len);
	xy = (t_xy *)malloc(sizeof(t_xy) * len);
	xy->x = game->player->x;
	xy->y = game->player->y;
	if (!visited || !xy)
		exit(1);
	while (i < len)
		visited[i++] = 0;
	visited[xy->y * game->map->wid + xy->x] = 1;
	if (!dfs(game, visited, game->map->collect_cnt, xy))
		exit_error_free(game, MAP_CANT_EXIT);
	free(xy);
	xy = NULL;
}
