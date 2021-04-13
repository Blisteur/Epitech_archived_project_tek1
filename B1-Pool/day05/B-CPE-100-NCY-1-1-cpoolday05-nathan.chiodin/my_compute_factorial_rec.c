/*
** EPITECH PROJECT, 2020
** my_compute_factorial_rec
** File description:
** task02
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb >= 13)
        return (0);
    if (nb == 1 || nb == 0)
        return (1);
    if (nb > 1)
        nb = nb * my_compute_factorial_rec(nb - 1);
    return (nb);
}
