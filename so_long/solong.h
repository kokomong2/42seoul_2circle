/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:53:02 by sgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:33:52 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./mlx/mlx.h"
# include "./GNL/get_next_line.h"
# include <fcntl.h> //open 위해 사용
# include <stdio.h> //test 용

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define MAP_ROUTE "./maps/"

# define MAP_ERR_MSG "맵이 유효하지 않습니다."
# define ARG_ERR_MSG "입력값이 하나가 아닙니다."
# define FILENAME_ERR_MSG "존재하는 파일명이 아닙니다."

typedef struct s_map
{
	char		*line;
	int			collect_cnt;
	int			win_height;
	int			win_width;
	int			map_height;
	int			map_width;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			move_cnt;
}				t_player;

typedef struct s_img
{
	int			img_wi;
	int			img_he;
	void		*blank;
	void		*wall;
	void		*collection;
	void		*exit;
	void		*player;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	int			bit;
	t_map		*map;
	t_player	*player;
	t_img		*img;
}				t_game;

t_game	*init_game(char *file);
int		copymap(t_game *game);

void	exit_error_free(t_game *game, char *msg);
void	exit_error(char *msg);
void	check_map(t_game *game);
void	drawmap(t_game *game);
int		key_press(int keycode, t_game *game);
void	free_game(t_game *game);
int	exit_game(t_game *game);

#endif