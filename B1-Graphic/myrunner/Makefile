##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/ -g

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../../
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

init:
	cd lib/my/ && make init
	cd ../../

debug: CFLAGS += -g

debug:	$(OBJ)
	cd lib/my/ && make
	cd ../../
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

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