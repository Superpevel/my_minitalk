SRCS=		../libft/libft.a server.c ../printf/printf.a

CC=		gcc

NAME=		server

CFLAGS +=
CFLAGS +=	-Wall -Wextra -Werror
OBJS=		$(SRCS:.c=.o)

all:		$(NAME)


$(NAME):	$(OBJS) ../minitalk.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)


clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re