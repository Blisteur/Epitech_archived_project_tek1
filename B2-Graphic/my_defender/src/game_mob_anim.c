/*
** EPITECH PROJECT, 2021
** anim mob
** File description:
** file 1
*/

#include "my_defender.h"

void game_mob_anim(my_struct_t *store)
{
    game_mob_link_t *tmp = store->game->first_mob;

    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        tmp->rec.left += 32;
        if (tmp->rec.left > 64)
            tmp->rec.left = 0;
        sfSprite_setTextureRect(tmp->sprite, tmp->rec);
        tmp = tmp->next;
    }
}