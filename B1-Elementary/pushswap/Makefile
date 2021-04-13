##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

SRC	=	main.c \
		error_handler.c \
		struct_handler.c \
		excep_handler.c \
		swap_push.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../../
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy

init:
	cd lib/my/ && make init
	cd ../../

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

re_debug: fclean debug