/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** 
*/

int my_print_digits(void)
{
    unsigned int print = 48;

    while (print < 58) {
        my_putchar(print);
        print ++;
    }
    my_putchar('\n');
    return (0);
}
