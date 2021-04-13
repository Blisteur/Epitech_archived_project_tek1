/*
** EPITECH PROJECT, 2020
** my_rev_params
** File description:
** task05
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
    int count;
    int temp = 0;

    for (count = 0; count != argc; count++)
        temp++;
    temp = temp - 1;
    for (temp; temp >= 0; temp--)
        my_putstr(argv[temp]);
    return (0);
}
