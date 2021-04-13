##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

SRC	=	main.c \
		error_handler.c \
		get_user.c \
		help.c \
		navy.c \
		struct_handler.c \
		map.c \
		verif_map.c \
		verif_map2.c \
		sigaction.c \
		print_map.c \
		attack.c \
		verif_end_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

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
	find -name "vgcore.*" -delete
	cd lib/my/ && make clean
	cd ../../

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make fclean
	cd ../../

re: fclean all

re_debug: fclean debug