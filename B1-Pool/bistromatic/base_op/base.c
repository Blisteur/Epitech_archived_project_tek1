/*
** EPITECH PROJECT, 2020
** base
** File description:
** file 1
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/bistromatic.h"
#include "../include/my.h"

void verif_base(char *str)
{
    char verif = 'X';

    for (int count = 0; str[count] != '\0'; count += 1) {
        verif = str[count];
        for (int scount = 0; str[scount] != '\0'; scount += 1) {
            if (verif == str[scount] && count != scount) {
                my_putstr_error(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
    return;
}

void change_base(char *str, char *expr)
{
    char *index = "0123456789";

    for (int count = 0; expr[count] != '\0'; count += 1) {
        for (int x = 0; x <= 9; x += 1)
            expr[count] = (expr[count] == str[x]) ? index[x] : expr[count];
    }
    return;
}