/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** file 2
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/eval_expr.h"

int calculate(int exp1, int exp2, char op)
{
    int res = 0;

    if (op == '+')
        res = exp1 + exp2;
    if (op == '-')
        res = exp1 - exp2;
    if (op == '*')
        res = exp1 * exp2;
    if (op == '/')
        res = exp1 / exp2;
    if (op == '%')
        res = exp1 % exp2;
    return (res);
}