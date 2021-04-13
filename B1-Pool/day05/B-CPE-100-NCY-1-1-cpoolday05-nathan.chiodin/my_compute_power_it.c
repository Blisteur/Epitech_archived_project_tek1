/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int temp = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (p > 1 ) {
        nb = nb * temp;
        p --;
    }
    return (nb);
}
