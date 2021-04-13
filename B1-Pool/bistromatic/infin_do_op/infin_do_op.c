/*
** EPITECH PROJECT, 2020
** infin_do_op
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

char *infin_do_op(char **exptab, int sign_exp1, int sign_exp2)
{
    if (exptab[0][0] == '+' && sign_exp1 == sign_exp2)
        return (infinadd(exptab, sign_exp1, sign_exp2));
    if (exptab[0][0] == '+' && (sign_exp1 > sign_exp2 || sign_exp1 < sign_exp2))
        return (infinsub(exptab, sign_exp1, sign_exp2));
    if (exptab[0][0] == '-' && sign_exp1 == sign_exp2)
        return (infinsub(exptab, sign_exp1, sign_exp2));
    if (exptab[0][0] == '-' && (sign_exp1 > sign_exp2 || sign_exp1 < sign_exp2))
        return (infinadd(exptab, sign_exp1, sign_exp1));
    if (exptab[0][0] == '*')
        return (infinmul(exptab, sign_exp1, sign_exp2));
    if (exptab[0][0] == '/')
        return (infindiv(exptab, sign_exp1, sign_exp2));
    if (exptab[0][0] == '%')
        infinadd(exptab, sign_exp1, sign_exp2);
    return ("NULL");
}