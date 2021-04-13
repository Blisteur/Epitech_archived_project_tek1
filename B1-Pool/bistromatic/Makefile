##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

SRC	=	./eval_expr/eval.c	\
		./eval_expr/evalsuite.c \
		./infin_do_op/infin_do_op_setup.c \
		./infin_do_op/infin_do_op.c \
		./infin_do_op/infinadd_1.c \
		./infin_do_op/infindiv_1.c \
		./infin_do_op/infinmul_1.c \
		./infin_do_op/infinsub_1.c \
		./infin_do_op/initialise_result.c \
		./infin_do_op/strncpyspe.c \
		./infin_do_op/verifsign.c \
		./base_op/base_op.c \
		./base_op/op.c \
		./base_op/base.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

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
	rm -f *.o
	rm -f eval_expr/*.o
	rm -f infin_do_op/*.o
	rm -f base_op/*.o
	cd lib/my/ && make clean
	cd ../../

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make fclean
	cd ../../

re: all fclean
