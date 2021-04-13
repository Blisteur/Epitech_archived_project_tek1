/*
** EPITECH PROJECT, 2020
** main
** File description:
** bistro
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/bistromatic.h"
#include "include/eval_expr.h"
#include "include/base_op.h"
#include "include/my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr_error(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr_error(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

void help(int argc, char *h)
{
    int lenh = my_strlen(h);

    if (argc == 2 && lenh == 2) {
        if (h[0] == '-' && h[1] == 'h') {
            my_putstr_error("USAGE\n");
            my_putstr_error("./calc base operators size_read\n\n");
            my_putstr_error("DESCRIPTION\n");
            my_putstr_error("- base: all the symbols of the base\n");
            my_putstr_error("- operators: the symbols for the parentheses");
            my_putstr_error(" and the 5 operators\n");
            my_putstr_error("- size_read: number of characters to be read\n");
            exit(0);
        }
    }
}

static void check_ops(char *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    verif_operators(ops);
}

static void check_base(char *b)
{
    if (my_strlen(b) < 2) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    verif_base(b);
}

int main(int argc, char **argv)
{
    unsigned int size;
    char *expr;

    if (argc == 2)
        help(argc, argv[1]);
    if (argc != 4) {
        my_putstr_error("Usage: ");
        my_putstr_error(argv[0]);
        my_putstr_error(" base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(argv[1]);
    check_ops(argv[2]);
    size = my_atoi(argv[3]);
    expr = get_expr(size);
    base_op(argv, expr);
    my_put_nbr(eval_expr(expr));
    free(expr);
    return (EXIT_SUCCESS);
}
