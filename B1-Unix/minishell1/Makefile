##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -I include/

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy

init:
	cd lib/my/ && $(make) init

debug: CFLAGS += -Wall -Wextra -g

debug:		$(OBJ)
	cd lib/my/ && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) -L lib -lmy

clean:
	find -name "*.o" -delete
	find -name "vgcore.*" -delete
	cd lib/my/ && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && $(MAKE) fclean

re: fclean all

re_debug: fclean debug