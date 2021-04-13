/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** 
*/

int my_print_alpha(void)
{
    int print = 'a';

    while (print <= 'z') {
        my_putchar(print);
        print ++;
    }
    my_putchar('\n');
    return (0);
}
