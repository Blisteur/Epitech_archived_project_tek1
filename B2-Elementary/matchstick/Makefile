##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

LDFLAGS = -L lib -lmy

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:
	$(MAKE) -C lib/my/
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g

debug:	$(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

final_test: CFLAGS += -Werror -g

final_test:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	find -name "*.o" -delete
	find -name "vgcore.*" -delete
	$(MAKE) -C lib/my/ clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C lib/my/ fclean

re: fclean all

re_debug: fclean debug

.PHONY: all debug clean fclean re re_debug