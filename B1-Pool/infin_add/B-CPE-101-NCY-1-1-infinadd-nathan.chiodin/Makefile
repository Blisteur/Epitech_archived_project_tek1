##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	infinadd_1.c \
		infinadd_2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../../
	gcc -o $(NAME) $(OBJ) -L lib -lmy -I include/my.h
clean:
	rm -f *.o
fclean:	clean
	rm -f $(NAME)
re: all fclean