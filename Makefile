SRCS=		main.c libft/libft.a


NAME=		make

CFLAGS +=	
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.


all:
	$(MAKE) -C server
	$(MAKE) -C client

clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re