/*
** EPITECH PROJECT, 2021
** struct_handler
** File description:
** file 1
*/

#include "my_sokoban.h"

my_struct *init_stuct(void)
{
    my_struct *store = malloc(sizeof(my_struct));

    if (store == NULL) {
        my_putstr_error("ERROR: malloc NULL !\n");
        exit(84);
    }
    store->map = NULL;
    store->ddmap = NULL;
    store->first_obj = NULL;
    store->last_obj = NULL;
    store->nb_line_map = 0;
    store->nbr_obj = 0;
    store->loop_stop = 0;
    store->nb_columns_map = 0;
    return (store);
}

void destroy_struct(my_struct *store, int output)
{
    if (store->map != NULL)
        free(store->map);
    if (store->ddmap != NULL) {
        for (int nb = 0; nb < store->nb_line_map; nb += 1) {
            if (store->ddmap[nb] != NULL)
                free(store->ddmap[nb]);
        }
        free(store->ddmap);
    }
    while (store->nbr_obj > 0)
        remove_link(store, store->first_obj);
    free(store);
    if (output == 84)
        exit(84);
    if (output == 1)
        exit(0);
}