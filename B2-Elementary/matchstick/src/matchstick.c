/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** file 1
*/

#include "matchstick.h"

void print_map(my_struct_t *store)
{
    for (int nb = 0; nb < (store->nb_lines + 2); nb += 1) {
        my_printf("%s\n", store->map[nb]);
    }
}

int loop_inputs(my_struct_t *store, const char *str, int type)
{
    char *buff = NULL;
    size_t buff_size = 0;
    int length = 0;
    int lock = 0;

    while (lock != 1) {
        my_printf("%s", str);
        length = getline(&buff, &buff_size, stdin);
        if (length == -1) {
            store->game_loop = 1;
            lock = 1;
        }
        if ((length > 0 &&
            verif_inputs(store, buff, type) == 0) || type == 2)
            lock = 1;
    }
    free(buff);
    return (store->game_loop);
}

int user_turn(my_struct_t *store)
{
    int lock = 0;

    store->get_user_line = 0;
    store->get_user_matchstick = 0;
    my_printf("\nYour turn:\n");
    while (lock == 0) {
        if (loop_inputs(store, "Line: ", 1) == 1)
            return (1);
        if (loop_inputs(store, "Matches: ", 2) == 1)
            return (1);
        if (store->get_user_line != 0 && store->get_user_matchstick != 0)
            lock = 1;
    }
    my_printf("Player removed %d match(es) from line %d\n"
    , store->get_user_matchstick, store->get_user_line);
    remove_matchstick(store);
    return (0);
}

void matchstick(my_struct_t *store)
{
    if (create_map(store) == 84) {
        store->nb_return = 84;
        return;
    }
    while (store->game_loop == 0) {
        print_map(store);
        if (user_turn(store) == 1)
            break;
        if (verif_end(store, 2) == 1)
            break;
        print_map(store);
        ai_turn(store);
        verif_end(store, 1);
    }
}