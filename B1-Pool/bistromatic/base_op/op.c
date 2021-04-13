/*
** EPITECH PROJECT, 2020
** op
** File description:
** file 1
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/bistromatic.h"
#include "../include/my.h"

void verif_operators(char *str)
{
    char verif = 'X';

    for (int count = 0; str[count] != '\0'; count += 1) {
        verif = str[count];
        for (int scount = 0; str[scount] != '\0'; scount += 1) {
            if ((verif == str[scount] && count != scount)
            || (str[scount] >= '0' && str[scount] <= '9')) {
                my_putstr_error(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
    return;
}

void verif_operators_expr(char *str, char *expr)
{
    char ver = 'X';
    int nb = 0;
    int max = 0;
    int tmp = 0;

    for (int count = 0; str[count] != '\0'; count += 1) {
        ver = str[count];
        for (int subcn = 0; expr[subcn] != '\0'; subcn += 1) {
            if (expr[subcn] < '0' || expr[subcn] > '9')
                max += 1;
            if (ver != expr[subcn] && (expr[subcn] < '0' || expr[subcn] > '9'))
                nb += 1;
        }
    }
    tmp = max / 7;
    if ((tmp + nb) != max) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    return;
}

void change_operators(char *str, char *expr)
{
    char *index = "()+-*/%";

    for (int count = 0; expr[count] != '\0'; count += 1) {
        for (int x = 0; x <= 6; x += 1)
            expr[count] = (expr[count] == str[x]) ? index[x] : expr[count];
    }
    return;
}