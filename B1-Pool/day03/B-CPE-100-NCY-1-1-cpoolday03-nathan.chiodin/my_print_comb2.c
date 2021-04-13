/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** 
*/

int my_print_comb2(void)
{
    int nb1 = 0;
    int nb2 = 0;

    while (nb1 < 98) {
        nb2 ++;
        if (nb2 >= 100){
            nb1 ++;
            nb2 = nb1 + 1;
        }
        my_putchar(((nb1 / 10) % 10) + 48);
        my_putchar((nb1 % 10) + 48);
        my_putchar(' ');
        my_putchar(((nb2 / 10) % 10) + 48);
        my_putchar((nb2 % 10) + 48);
        if (nb1 != 98){
            my_putchar(',');
            my_putchar(' ');
        } else
            my_putchar('\n');
    }
}
