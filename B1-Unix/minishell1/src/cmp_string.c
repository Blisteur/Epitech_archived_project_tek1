/*
** EPITECH PROJECT, 2021
** compare_string
** File description:
** file 1
*/

#include "mysh.h"

int compare_string(char *str1, char *str2)
{
    for (int nb = 0; str2[nb]; nb += 1) {
        if (str1[nb] != str2[nb])
            return (1);
    }
    return (0);
}

int compare_string_n(char *str1, char *str2, int n)
{
    for (int nb = 0; nb < n; nb += 1) {
        if (str1[nb] != str2[nb])
            return (1);
    }
    return (0);
}