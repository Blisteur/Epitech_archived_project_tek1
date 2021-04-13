##
## EPITECH PROJECT, 2020
## makefile
## File description:
## task01
##

SRCLIB	=	$(wildcard *.c)

OBJLIB	=	$(SRCLIB:.c=.o)

NAMELIB	=	libmy.a

NAME_H	=	eval_expr.h

libmy:	$(OBJLIB)
	ar rc $(NAMELIB) $(OBJLIB)
	cp $(NAMELIB) ..
	cp $(NAME_H) ../../include/$(NAME_H)

clean:
	rm -f *.o

fclean:
	rm libmy.a
	rm ../libmy.a