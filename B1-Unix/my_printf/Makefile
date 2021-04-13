##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	my_printf.c \
		convert/convert.c \
		flags/flags.c \
		formater/formater.c \
		length/length.c \
		precision/precision.c \
		specifier/specifier.c \
		width/width.c \
		util_file/my_getnbr.c \
		util_file/my_nbrlen.c \
		util_file/my_put_bin.c \
		util_file/my_put_hex.c \
		util_file/my_put_nbr.c \
		util_file/my_put_octal.c \
		util_file/my_put_p.c \
		util_file/my_putchar.c \
		util_file/my_putstr.c \
		util_file/my_putstr_nprint.c \
		util_file/my_strlen.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	find -name "*.o" -delete
clean:
	find -name "*.o" -delete
fclean:		clean
	rm libmy.a
re:		fclean all