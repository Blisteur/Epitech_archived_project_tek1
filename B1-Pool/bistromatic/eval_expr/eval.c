/*
** EPITECH PROJECT, 2020
** eval_xpr
** File description:
** desc
*/

#include <stdlib.h>
#include "../include/bistromatic.h"
#include "../include/eval_expr.h"
#include "../include/my.h"

int number(char **str)
{
    int minus = 1;
    int nb1 = 0;

    if ((*str)[0] == '+' || (*str)[0] == '-') {
        if ((*str)[0] == '-')
            minus = -1;
        (*str)++;
    }
    if ((*str)[0] == '(') {
        (*str)++;
        nb1 = summands(str);
        if ((*str)[0] == ')')
            (*str)++;
        return (nb1 * minus);
    }
    while ((*str)[0] >= '0' && (*str)[0] <= '9') {
        nb1 = (nb1 * 10) + ((*str)[0] - '0');
        (*str)++;
    }
    return (nb1 * minus);
}

int summands(char **str)
{
    int nb1 = number (str);
    int nb2;
    char ope;

    while ((*str)[0] != 0 && (*str)[0] != ')') {
        ope = (*str)[0];
        (*str)++;
        if (ope == '+' || ope == '-') {
            nb2 = factors(str);
        }
        else
            nb2 = number(str);
        if ((ope == '/' || ope == '%') && nb2 == 0) {
            my_putstr_error(ERROR_MSG);
            exit(DIVISION_BY_0);
        }
        nb1 = do_op(nb1, nb2, ope);
    }
    return (nb1);
}

int factors(char **str)
{
    int nb1 = number(str);
    char ope;

    while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%') {
        ope = (*str)[0];
        (*str)++;
        nb1 = do_op(nb1, number(str), ope);
    }
    return (nb1);
}

int eval_expr(char *str)
{
    if (str[0] == 0)
        return (0);
    return (summands(&str));
}
