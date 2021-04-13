/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int n)
{
    int nb = n;
    int diviser = 1;

    if (nb < 0)
        my_putchar('-');
    while (nb != 0 && (nb/diviser) >= 10) {
        diviser *= 10;
    }
    while (diviser > 0) {
        if (nb != 0)
            nb = n / diviser;
        if (nb != 0)
            nb = nb % 10;
        char c = '0' + nb;
        my_putchar(c);
        if (diviser == 1 || diviser == 0)
            diviser = 0;
        else
            diviser /= 10;
    }
}

