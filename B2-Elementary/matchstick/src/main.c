/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "matchstick.h"

int main(const int argc, const char * const * argv)
{
    my_struct_t *store = init_struct();

    if (error_handler(store, argc, argv) == 84) {
        destroy_struct(store);
        return (84);
    }
    matchstick(store);
    return (destroy_struct(store));
}