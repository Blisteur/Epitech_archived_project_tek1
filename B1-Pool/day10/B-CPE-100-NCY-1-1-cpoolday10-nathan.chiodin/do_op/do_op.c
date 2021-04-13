/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** task02
*/
#include <stdio.h>
#include "../include/my.h"

void do_op(char **argv)
{
    int res = 0;
    int op2 = my_getnbr(argv[3]);
    int op1 = my_getnbr(argv[1]);
    char ope = argv[2][0];

    if (ope == '+')
        res = op1 + op2;
    if (ope == '-')
        res = op1 - op2;
    if (ope == '*')
        res = op1 * op2;
    if (ope == '/')
        res = op1 / op2;
    if (ope == '%')
        res = op1 % op2;
    my_put_nbr(res);
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    if (argv[2][0] < '%' && argv[2][0] > '%' &&
        argv[2][0] < '*' && argv[2][0] > '+' &&
        argv[2][0] < '-' && argv[2][0] > '-' &&
        argv[2][0] < '/' && argv[2][0] > '/') {
        my_putchar('0');
        return (84);
    }
    if (argv[2][0] == '/' && argv[1][0] == '0' ||
        argv[2][0] == '/' && argv[3][0] == '0') {
        write(2, "Stop: division by zero\n", 24);
        return (84);
        }
    if (argv[2][0] == '%' && argv[1][0] == '0' ||
        argv[2][0] == '%' && argv[3][0] == '0') {
        write(2, "Stop: modulo by zero\n", 22);
        return (84);
        }
    if (argc < 4 || argc > 4)
        return (84);
    do_op(argv);
    return (0);
}