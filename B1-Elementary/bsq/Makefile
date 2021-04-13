##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/ -O

SRC	=	bsq.c \
		manage_struct.c \
		error_management.c \
		verif_excep.c \
		print_bsq.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../../
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy

debug: CFLAGS += -Werror -g

debug:	$(OBJ)
	cd lib/my/ && make
	cd ../../
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy

clean:
	find -name "*.o" -delete
	cd lib/my/ && make clean
	cd ../../

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make fclean
	cd ../../

re: fclean all
