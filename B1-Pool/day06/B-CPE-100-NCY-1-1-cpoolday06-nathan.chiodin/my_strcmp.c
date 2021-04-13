/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** task06
*/
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    for (int column = 0; s1[column] != '\0'
             || s2[column] != '\0'; column ++) {
        for (int count = 0; count < 127; count ++) {
            if (s1[column] > s2[column])
                return (1);
            if (s1[column] < s2[column])
                return (-1);
        }
    }
    return (0);
}
