/*
** EPITECH PROJECT, 2020
** excep_handler
** File description:
** file 1
*/

#include "include/push_swap.h"

int excep_handler(int argc, char **argv)
{
    int tmp = 0;

    if (argc == 2) {
        my_putchar('\n');
        return (1);
    }
    for (int nb = 2; nb < argc; nb += 1) {
        if (my_getnbr(argv[nb - 1]) > my_getnbr(argv[nb]))
            tmp += 1;
    }
    if (tmp == 0) {
        my_putchar('\n');
        return (1);
    }
    return (0);
}