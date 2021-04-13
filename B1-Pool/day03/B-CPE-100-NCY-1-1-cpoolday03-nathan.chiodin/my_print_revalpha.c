/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** 
*/

int my_print_revalpha(void)
{
    int print = 'z';

    while (print >= 'a') {
        my_putchar(print);
        print --;
    }
    my_putchar('\n');
    return (0);
}
