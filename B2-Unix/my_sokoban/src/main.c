/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "my_sokoban.h"

int main(const int argc, const char * const *argv)
{
    my_struct *store = NULL;
    int win_code = 0;

    store = init_stuct();
    error_handler(store, argc, argv);
    win_code = sokoban(store);
    destroy_struct(store, 0);
    return (win_code);
}