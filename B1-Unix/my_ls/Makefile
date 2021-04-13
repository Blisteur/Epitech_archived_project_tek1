##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

SRC	=	main.c \
		main2.c \
		struct.c \
		error_management.c \
		verif_link.c \
		convert_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

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

re: all fclean
