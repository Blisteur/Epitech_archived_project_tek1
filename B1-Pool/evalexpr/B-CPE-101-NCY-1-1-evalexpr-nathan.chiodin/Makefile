##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	main.c \
		evalexpr_1.c \
		evalexpr_2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

NAME_H	=	eval_expr.h

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../../
	gcc -o $(NAME) $(OBJ) -L lib -lmy -I include/$(NAME_H)

clean:
	rm -f *.o
	cd lib/my/ && make clean
	cd ../../

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make fclean
	cd ../../

re: all fclean