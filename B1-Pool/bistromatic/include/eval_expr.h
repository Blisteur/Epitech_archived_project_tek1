/*
** EPITECH PROJECT, 2020
** eval_xpr
** File description:
** desc
*/

#ifndef EVAL_EXPR
#define EVAL_EXPR

int summands(char **str);
int factors(char **str);
int eval_expr(char *str);
int do_op(int nb1, int nb2, char ope);
int number(char **str);

#endif /* EVAL_EXPR */