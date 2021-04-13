/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** file 1
*/

#include "include/navy.h"

my_struct *store;

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == 0)
        return (help());
    store = init_struct();
    if (error_handler(argc, argv, store) == 84) {
        destroy_struct(store);
        return (84);
    }
    get_user(store, argc, argv);
    navy(store);
    destroy_struct(store);
    return (0);
}