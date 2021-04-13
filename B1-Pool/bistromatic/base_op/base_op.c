/*
** EPITECH PROJECT, 2020
** base_op
** File description:
** file 1
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/base_op.h"
#include "../include/bistromatic.h"
#include "../include/my.h"

void base_op(char **argv, char *expr)
{
    verif_operators_expr(argv[2], expr);
    change_operators(argv[2], expr);
    change_base(argv[1], expr);
}