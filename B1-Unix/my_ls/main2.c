/*
** EPITECH PROJECT, 2020
** main2
** File description:
** file 2
*/

#include "include/my_ls.h"

void convert_time(char *str, my_struct *store)
{
    int tmp = 0;
    for (int nb = 4; nb <= 15; nb += 1, tmp += 1)
        str[tmp] = str[nb];
    str[tmp] = '\0';
    store->time = str;
}

void convert_octal(my_struct *store, unsigned int nb)
{
    if (nb < 8) {
        if (store->right > 0) {
            store->right *= 10;
            store->right += nb;
        }
        if (store->right == 0)
            store->right = nb;
    } else if (nb > 7) {
        convert_octal(store, nb / 8);
        convert_octal(store, nb % 8);
    }
    return;
}

void calcul_right(int nb, char *str)
{
    if (nb / 4 >= 1) {
        nb -= 4;
        str[0] = 'r';
    }
    if (nb / 2 >= 1) {
        nb -= 2;
        str[1] = 'w';
    }
    if (nb / 1 >= 1) {
        nb -= 1;
        str[2] = 'x';
    }
}

void type_file(unsigned int type, char *str)
{
    if (S_ISDIR(type) == 1)
        str[0] = 'd';
    if (S_ISREG(type) == 1)
        str[0] = '-';
    if (S_ISCHR(type) == 1)
        str[0] = 'c';
    if (S_ISBLK(type) == 1)
        str[0] = 'b';
    if (S_ISFIFO(type) == 1)
        str[0] = 'p';
    if (S_ISLNK(type) == 1)
        str[0] = 'l';
}

void print_right(my_struct *store, unsigned int nb)
{
    char tab[] = "----------";

    store->right = 0;
    type_file(nb, tab);
    convert_octal(store, nb);
    calcul_right((store->right % 1000) / 100, tab + 1);
    calcul_right((store->right % 100) / 10, tab + 4);
    calcul_right((store->right % 10), tab + 7);
    store->list_right = tab;
}