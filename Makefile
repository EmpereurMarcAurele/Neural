NAME	=	network

CC	=	gcc

CFLAGS	=	-Wall -Wextra

SRC	=	neural.c	\
		fill_network.c	\
		print.c

OBJ	= $(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)


clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(OBJ) $(NAME)

re	:	fclean all
