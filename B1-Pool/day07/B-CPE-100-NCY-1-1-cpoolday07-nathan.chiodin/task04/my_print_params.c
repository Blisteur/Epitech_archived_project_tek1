/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** task04
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        my_putchar(str[count]);
        count++;
    }
    my_putchar('\n');
    return (0);
}

int main(int argc, char **argv)
{
    for (int count = 0; count != argc; count++)
        my_putstr(argv[count]);
    return (0);
}
