SRCS=		../libft/libft.a client.c

CC=		gcc 

NAME=		client

CFLAGS +=	
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) 


clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re