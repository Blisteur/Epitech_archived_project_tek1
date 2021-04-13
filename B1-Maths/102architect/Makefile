##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/ -g

SRC	=	main.c \
		struct.c \
		calculate.c \
		error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug: CFLAGS += -Werror -g

debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	find -name "*.o" -delete

fclean:	clean
	rm -f $(NAME)

re: all fclean
