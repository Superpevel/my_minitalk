SRCS=	libft/libft.a printf/printf.a


NAME=		make

CFLAGS +=
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

.DEFAULT_GOAL := all

all:
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	$(MAKE) -C ./server
	$(MAKE) -C ./client

$(NAME):	minitalk.h Makefile
		$(MAKE) -C libft
		$(MAKE) -C server
		$(MAKE) -C client
clean:
	cd printf && $(MAKE) clean
	cd libft && $(MAKE) clean
	cd server && $(MAKE) clean
	cd client && $(MAKE) clean

fclean:		clean
	cd printf && $(MAKE) fclean
	cd libft && $(MAKE) fclean
	cd server && $(MAKE) fclean
	cd client && $(MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re