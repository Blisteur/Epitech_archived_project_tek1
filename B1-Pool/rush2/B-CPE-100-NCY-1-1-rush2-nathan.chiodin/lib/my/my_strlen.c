/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** simple description
*/

int my_strlen(char const *str)
{
    int size = 0;
    while (*str != '\0'){
        size++;
        str++;
    }
    return size;
}
