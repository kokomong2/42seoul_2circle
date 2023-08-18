/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:53:02 by sgo               #+#    #+#             */
/*   Updated: 2023/08/18 17:33:29 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./mlx/mlx.h"
# include "./GNL/get_next_line.h"
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define MAP_ROUTE		"./maps/"

# define MAP_ERR_MSG		"맵이 유효하지 않습니다."
# define MAP_REC_ERR		"맵이 직사각형이 아닙니다"
# define MAP_DUP_ERR		"플레이어 혹은 출구가 하나가 아닙니다."
# define MAP_WALL_ERR		"맵이 벽으로 둘러쌓여있지 않습니다."
# define MAP_CANT_EXIT		"플레이어가 나가는 조건을 만족할수 없습니다."
# define ARG_ERR_MSG		"입력값이 하나가 아닙니다."
# define FILENAME_ERR_MSG	"존재하는 파일명이 아닙니다."
# define MALLOC_ERR			"malloc 실패"

typedef struct s_map
{
	char		*line;
	int			player_cnt;
	int			exit_cnt;
	int			collect_cnt;
	int			win_hei;
	int			win_wid;
	int			hei;
	int			wid;
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
	void		*col;
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

typedef struct s_xy
{
	int			x;
	int			y;
	int			is_exit;
}				t_xy;

t_game	*init_game(char *file);
int		copymap(t_game *game);
void	exit_error_free(t_game *game, char *msg);
void	exit_error(char *msg);
void	count_map(t_game *game);
void	check_map(t_game *game, int len);
void	check_wall(t_game *game);
void	drawmap(t_game *game);
int		key_press(int keycode, t_game *game);
void	free_game(t_game *game);
int		exit_game(t_game *game);
void	check_dfs(t_game *game);
void	ft_free(void *input);
void	write_num(int num);

#endif