/*
** EPITECH PROJECT, 2020
** evalsuite
** File description:
** 2nd one
*/

#include <stdlib.h>
#include "../include/bistromatic.h"
#include "../include/eval_expr.h"
#include "../include/my.h"

int do_op(int nb1, int nb2, char ope)
{
    int result = 0;

    switch (ope) {
    case '+':
        result = nb1 + nb2;
        break;
    case '-':
        result = nb1 - nb2;
        break;
    case '*':
        result = nb1 * nb2;
        break;
    case '/':
        result = nb1 / nb2;
        break;
    case '%':
        result = nb1 % nb2;
        break;
    }
    return (result);
}