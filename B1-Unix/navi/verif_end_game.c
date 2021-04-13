/*
** EPITECH PROJECT, 2020
** verif_end_game
** File description:
** file 1
*/

#include "include/navy.h"

int verif_end_game(my_struct *store)
{
    int life_ally = 0;
    int life_enemy = 0;

    for (int y = 2; y < 10; y += 1) {
        for (int x = 2; x < 17; x += 2) {
            if (store->ally_map[x][y] == 'x')
                life_ally += 1;
            if (store->enemy_map[x][y] == 'x')
                life_enemy += 1;
        }
    }
    if (life_ally == 14 || life_enemy == 14) {
        print_map(store);
        if (life_ally == 14)
            my_printf("\nEnemy won\n");
        else
            my_printf("\nI won\n");
        return (1);
    }
    return (0);
}