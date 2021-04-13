/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** task01
*/
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    for (count = 0; src[count] != '\0'; count++)
        dest[count] = src[count];
    return (dest);
}
