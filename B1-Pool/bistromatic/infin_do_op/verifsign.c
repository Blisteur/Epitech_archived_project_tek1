/*
** EPITECH PROJECT, 2020
** verifsign
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

int verifsign(char *str)
{
    int sign_neg = 1;

    for (int count = 0; str[count] != '\0'; count += 1) {
        if (str[count] == '-') {
            str[count] = '0';
            sign_neg = sign_neg * -1;
        }
        if (str[count] == '+')
            str[count] = '0';
    }
    return (sign_neg);
}