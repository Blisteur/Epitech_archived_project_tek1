/*
** EPITECH PROJECT, 2021
** struct handler
** File description:
** file 1
*/

#include "matchstick.h"

my_struct_t *init_struct(void)
{
    my_struct_t *store = malloc(sizeof(my_struct_t));

    if (store == NULL)
        return (NULL);
    store->nb_lines = 0;
    store->nb_matchstick = 0;
    store->game_loop = 0;
    store->nb_return = 0;
    store->map = NULL;
    store->get_user_line = 0;
    store->get_user_matchstick = 0;
    return (store);
}

int destroy_struct(my_struct_t *store)
{
    int tmp = 0;

    if (store != NULL) {
        destroy_map(store);
        tmp = store->nb_return;
        free(store);
    }
    return (tmp);
}