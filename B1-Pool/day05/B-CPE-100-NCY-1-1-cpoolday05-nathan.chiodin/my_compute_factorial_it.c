/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** task01
*/

int my_compute_factorial_it(int nb)
{
    int temp = nb;

    if (nb < 0 || nb >= 13)
        return (0);
    if (nb == 1 || nb == 0)
        return (1);
    while (temp > 1) {
        temp --;
        nb = nb * temp;
    }
    return (nb);
}
