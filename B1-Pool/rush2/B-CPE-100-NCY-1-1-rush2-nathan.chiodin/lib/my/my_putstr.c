/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** simple description
*/

void my_putchar(char c);

int my_putstr(const char *str)
{
    int byte_size = 0;

    while (*str != '\0'){
        my_putchar(str[0]);
        *str++;
        byte_size++;
    }
    return byte_size;
}

