/*
** EPITECH PROJECT, 2021
** life handler
** File description:
** file 1
*/

#include "my_defender.h"

void verif_life_mob(my_struct_t *store, game_mob_link_t *mob)
{
    if (mob->life <= 0) {
        if (mob->type == BASE_SOLDAT)
            update_money_txt(store, 50, '+');
        if (mob->type == UP_SOLDAT)
            update_money_txt(store, 50, '+');
        if (mob->type == BASE_TANK)
            update_money_txt(store, 100, '+');
        if (mob->type == UP_TANK)
            update_money_txt(store, 100, '+');
        if (mob->type == MISSILE)
            update_money_txt(store, 400, '+');
        if (mob->type == BOSS_TANK)
            update_money_txt(store, 500, '+');
        store->game->nb_mob_money += mob->money;
        remove_mob_link(store, mob);
    }
}

void verif_life(my_struct_t *store)
{
    game_mob_link_t *tmp = store->game->first_mob;
    game_mob_link_t *tmp2 = NULL;

    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        if (tmp->pos.x == 1400 && tmp->pos.y == 400) {
            update_life_txt(store, tmp->damage);
            store->game->nb_mob_money += tmp->money;
            tmp2 = tmp;
            tmp = tmp->next;
            remove_mob_link(store, tmp2);
            audio_run_hurt(store);
        } else
            tmp = tmp->next;
    }
}