/*
** EPITECH PROJECT, 2021
** ai
** File description:
** file 1
*/

#include "matchstick.h"

void remove_one(my_struct_t *store)
{
    for (int nb = 1; nb < store->nb_lines + 1; nb += 1) {
        if (count_matchstick_in_line(store->map[nb]) > 0) {
            store->get_user_line = nb;
            store->get_user_matchstick = 1;
            break;
        }
    }
    remove_matchstick(store);
}

int xor(my_struct_t *store)
{
    unsigned int nb_xor = 0;

    nb_xor = count_matchstick_in_line(store->map[1]);
    for (int nb = 2; nb < store->nb_lines + 1; nb += 1) {
        nb_xor = nb_xor ^ count_matchstick_in_line(store->map[nb]);
    }
    return (nb_xor);
}

int test_remove(my_struct_t *store, int nb)
{
    int tmp = count_matchstick_in_line(store->map[nb]);
    char buff[calcul_lenght(store) + 1];
    int count = 0;

    buff[calcul_lenght(store)] = '\0';
    my_strcpy(buff, store->map[nb]);
    store->get_user_line = nb;
    for (count = 1; count < tmp && count < store->nb_matchstick; count += 1) {
        store->get_user_matchstick = 1;
        remove_matchstick(store);
        if (xor(store) == 0) {
            store->get_user_matchstick = count;
            return (1);
        }
    }
    if (xor(store) != 0) {
        my_strcpy(store->map[nb], buff);
    }
    return (0);
}

void ai_turn(my_struct_t *store)
{
    my_printf("\nAI's turn...\n");
    remove_one(store);
    my_printf("AI removed %d match(es) from line %d\n"
        , store->get_user_matchstick, store->get_user_line);
}