##
## EPITECH PROJECT, 2020
## makefile
## File description:
## task01
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f *.o
	cp $(NAME) ..
	cp my.h ../../include/my.h
clean:
	rm -f *.o
fclean:		clean
	rm libmy.a
	rm ../libmy.a
re:		fclean all