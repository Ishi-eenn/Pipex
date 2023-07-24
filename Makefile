NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c exec.c error.c file.c command.c free.c judge.c judge_is.c
OBJS	= $(SRCS:.c=.o)
LIBS	= -Llibft -lft
LIBFT	= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBS) $(CFLAGS)

$(LIBFT):
	$(MAKE) -C ./libft/

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all
