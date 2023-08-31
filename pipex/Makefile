# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 16:24:48 by sgo               #+#    #+#              #
#    Updated: 2023/08/31 16:49:04 by sgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = 	main.c \
		path.c cmd.c
LIB_NAME = libft.a
LIB_DIR = ./libft/
SRC_DIR = ./src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
LIBS = $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS = $(SRCS:.c=.o)

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME) : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	make clean -C $(LIB_DIR) 
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR) 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re