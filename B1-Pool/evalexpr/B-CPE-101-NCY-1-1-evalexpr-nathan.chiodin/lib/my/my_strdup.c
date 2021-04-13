/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** task01
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest;
    int src_len;

    src_len = my_strlen(src);
    dest = malloc(sizeof(char) * (src_len + 1));
    my_strcpy(dest, src);
    return (dest);
}
