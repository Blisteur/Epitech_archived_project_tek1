/*
** EPITECH PROJECT, 2021
** remove matchstick
** File description:
** file 1
*/

#include "matchstick.h"

void remove_matchstick(my_struct_t *store)
{
    int tmp = store->get_user_matchstick;

    for (int nb = calcul_lenght(store); store->get_user_matchstick > 0
    && nb > 0; nb -= 1) {
        if (store->map[store->get_user_line][nb] == '|') {
            store->map[store->get_user_line][nb] = ' ';
            store->get_user_matchstick -= 1;
        }
    }
    store->get_user_matchstick = tmp;
}