NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=thread
RM = rm -f
SRCS = main.c dining.c init.c  main.c util.c wait.c print.c time.c \
	monitoring.c free.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re