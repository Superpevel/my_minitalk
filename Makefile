SRCS=		main.c libft/libft.a


NAME=		make

CFLAGS +=
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.


all: $(NAME)

$(NAME):	minitalk.h Makefile
		$(MAKE) -C libft
		$(MAKE) -C server
		$(MAKE) -C client
clean:
	cd libft && $(MAKE) clean
	cd server && $(MAKE) clean
	cd client && $(MAKE) clean
	rm -rvf $(OBJS)

fclean:		clean
	cd server && $(MAKE) fclean
	cd client && $(MAKE) fclean
	cd libft && $(MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re