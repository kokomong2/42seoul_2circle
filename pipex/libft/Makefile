# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:13:27 by sgo               #+#    #+#              #
#    Updated: 2023/08/29 18:22:44 by sgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_memset.c \
		ft_split.c ft_stdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c \
		ft_strlcpy.c ft_memset.c ft_memcpy.c
OBJ_FILES = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY: all bonus clean fclean re