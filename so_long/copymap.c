/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copymap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:08:19 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 18:55:32 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	copyline(char *str, t_game *game)
{
	char	*line;

	line = game->map->line;
	if (line == NULL)
		line = ft_strdup(str);
	else
		line = ft_strjoin(line, str, get_strlen(str));
	if (!line)
		exit(1);
	game->map->line = line;
	return (0);
}

int	copymap(t_game *game)
{
	char	*str;

	str = get_next_line(game->fd);
	game->map->map_width = get_strlen(str);
	while (str != NULL)
	{
		game->map->map_height++;
		copyline(str, game);
		free(str);
		str = get_next_line(game->fd);
	}
	game->map->win_width = game->map->map_width * game->bit;
	game->map->win_height = game->map->map_height * game->bit;
	free(str);
	return (1);
}
