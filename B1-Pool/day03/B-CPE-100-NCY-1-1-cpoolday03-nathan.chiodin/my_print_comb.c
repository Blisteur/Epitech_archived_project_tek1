/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** 
*/

int my_print_comb(void)
{
    int nb1 = 0;

    while (nb1 <= 789) {
        if (((nb1 / 100) + 48) >= (((nb1 / 10) % 10) + 48) ||
            (((nb1 / 10) % 10) + 48) >= ((nb1 % 10) + 48) ||
            ((nb1 / 100) + 48) >= ((nb1 % 10) + 48)) {
            nb1 ++;
        } else {
            my_putchar((nb1 / 100) + 48);
            my_putchar(((nb1 / 10) % 10) + 48);
            my_putchar((nb1 % 10) + 48);
            if (nb1 != 789){
                my_putchar(',');
                my_putchar(' ');
            }
            nb1 ++;
        }
    }
    my_putchar('\n');
    return (0);
}
