# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 16:24:48 by sgo               #+#    #+#              #
#    Updated: 2023/09/27 17:38:37 by sgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = 	main.c \
		path.c cmd.c init.c validation.c open.c \
		child.c free.c wait.c
SRC_B = main_bonus.c \
		path_bonus.c cmd_bonus.c init_bonus.c validation_bonus.c open_bonus.c \
		child_bonus.c free_bonus.c wait_bonus.c here_doc_bonus.c
GNL = get_next_line_utils.c get_next_line.c
LIB_NAME = libft.a
LIB_DIR = ./libft/
GNL_DIR = ./gnl/
SRC_DIR = ./src/
SRCB_DIR = ./srcb/
INCS_DIR = ./include/pipex.h
INCS_BONUS_DIR = ./include/pipex_bonus.h

SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_B = $(addprefix $(SRCB_DIR), $(SRC_B))
LIBS = $(addprefix $(LIB_DIR), $(LIB_NAME))
GNLS = $(addprefix $(GNL_DIR), $(GNL))
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
GNL_O = $(GNLS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_B)
	INC_DIR = $(INCS_BONUS_DIR)
else
	OBJ_FILES = $(OBJS)
	INC_DIR = $(INCS_DIR)
endif

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME) : $(OBJ_FILES) $(LIBS) $(GNL_O)
	$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) $^

bonus:
	make WITH_BONUS=1

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS) $(OBJS_B) $(GNL_O)

fclean: clean
	$(RM) $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re