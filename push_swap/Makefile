# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgo <sgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:31:39 by sgo               #+#    #+#              #
#    Updated: 2023/07/27 15:45:42 by sgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rs
RM = rm -f
SRCS = main.c info_util.c stack_reverse.c stack_rotate.c \
stack_push_swap.c array_util.c indexing_stack_a.c sort_short.c\
pivot.c greedy.c greedy_util.c\
LIBFT/ft_atoi.c LIBFT/ft_split.c LIBFT/ft_strlcpy.c LIBFT/ft_strlen.c \
validation.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./LIBFT/

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#debug
debug	: fclean #이전에 만들어놓은 목적파일과 a파일 out파일 등을 삭제한다.
	gcc -g ${SRCS}
	lldb a.out "    9"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re