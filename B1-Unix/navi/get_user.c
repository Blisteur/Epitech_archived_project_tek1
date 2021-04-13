/*
** EPITECH PROJECT, 2020
** get_usr
** File description:
** file 1
*/

#include "include/navy.h"

void get_user(my_struct *store, int argc, char **argv)
{
    if (argc == 2) {
        store->usr = 1;
    } else if (argc == 3) {
        store->usr = 2;
        store->enemy_pid = my_getnbr(argv[1]);
    }
}