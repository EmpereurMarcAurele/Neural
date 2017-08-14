NAME	=	network

CC	=	gcc

CFLAGS	=	-Wall -Wextra

SRC	=	neural.c	\
		fill_network.c	\
		run_network.c	\
		activation_func.c	\
		print.c

OBJ	= $(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lm


clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(OBJ) $(NAME)

re	:	fclean all
