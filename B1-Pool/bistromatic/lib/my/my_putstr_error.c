/*
** EPITECH PROJECT, 2020
** error
** File description:
** file 1
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
    return (0);
}