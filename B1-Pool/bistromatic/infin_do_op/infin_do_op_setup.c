/*
** EPITECH PROJECT, 2020
** infin_do_op_setup
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

char *infin_do_op_setup(char *exp1, char *exp2, char op)
{
    char **exptab = malloc(sizeof(char *) * 3);
    int sign_exp1 = 0;
    int sign_exp2 = 0;
    char *res;

    exptab[0] = malloc(sizeof(char) * 2);
    exptab[0][0] = op;
    exptab[0][1] = '\0';
    exptab[1] = exp1;
    exptab[2] = exp2;
    sign_exp1 = verifsign(exptab[1]);
    sign_exp2 = verifsign(exptab[2]);
    res = infin_do_op(exptab, sign_exp1, sign_exp2);
    free(exptab[0]);
    free(exptab);
    return (res);
}