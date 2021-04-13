##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L ../lib -lmy
clean:
	rm -f *.o
fclean:	clean
	rm -f $(NAME)
re: all fclean