##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

init:
	cd lib/my/ && $(MAKE) init

debug: CFLAGS += -g

debug:		$(OBJ)
	cd lib/my/ && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
	find -name "*.o" -delete
	find -name "vgcore.*" -delete
	cd lib/my/ && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && $(MAKE) fclean

re: fclean all

re_debug: fclean debug