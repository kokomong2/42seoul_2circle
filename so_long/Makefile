# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 12:41:53 by sgo               #+#    #+#              #
#    Updated: 2023/08/18 17:20:53 by sgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx/
GL_LINK = -I $(MLX) -L $(MLX) -lmlx -framework OpenGl -framework AppKit
RM = rm -f
SRCS = main.c init_game.c copymap.c validation.c drawmap.c keypress.c \
free_game.c exit.c dfs.c write_util.c \
GNL/get_next_line.c GNL/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

clean:
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re