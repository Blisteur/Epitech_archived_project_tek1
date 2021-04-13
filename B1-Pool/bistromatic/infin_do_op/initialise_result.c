/*
** EPITECH PROJECT, 2020
** initialise_result
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

char *initialise_result(char *result, int len_nb)
{
    for (int count = 0; count != len_nb - 1; count += 1)
        result[count] = '0';
    result[len_nb - 1] = '\0';
    return (result);
}