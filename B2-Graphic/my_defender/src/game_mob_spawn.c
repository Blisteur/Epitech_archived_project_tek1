/*
** EPITECH PROJECT, 2021
** mob spawn
** File description:
** file 1
*/

#include "my_defender.h"

static void game_spawn_mob4(my_struct_t *store, int tmp, sfVector2f *pos)
{
    if (store->game->nb_mob_money >= 100) {
        tmp = (rand() % ((store->game->nb_mob_money / 100) + 1 - 0) + 0);
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_up_soldat, *pos);
            pos->x -= 50;
        }
        store->game->nb_mob_money -= tmp * 100;
    }
    if (store->game->nb_mob_money >= 25) {
        tmp = store->game->nb_mob_money / 25;
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_base_soldat, *pos);
            pos->x -= 50;
        }
        store->game->nb_mob_money -= tmp * 25;
    }
}

static void game_spawn_mob3(my_struct_t *store, int tmp, sfVector2f *pos)
{
    if (store->game->nb_mob_money >= 300) {
        tmp = (rand() % ((store->game->nb_mob_money / 300) + 1 - 0) + 0);
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_up_tank, *pos);
            pos->x -= 100;
        }
        store->game->nb_mob_money -= tmp * 300;
    }
    if (store->game->nb_mob_money >= 200) {
        tmp = (rand() % ((store->game->nb_mob_money / 200) + 1 - 0) + 0);
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_base_tank, *pos);
            pos->x -= 100;
        }
        store->game->nb_mob_money -= tmp * 200;
    }
}

static void game_spawn_mob2(my_struct_t *store, int tmp, sfVector2f *pos)
{
    if (store->game->nb_mob_money >= 400) {
        tmp = (rand() % ((store->game->nb_mob_money / 400) + 1 - 0) + 0);
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_boss_tank, *pos);
            pos->x -= 120;
        }
        store->game->nb_mob_money -= tmp * 400;
    }
    if (store->game->nb_mob_money >= 350) {
        tmp = (rand() % ((store->game->nb_mob_money / 350) + 1 - 0) + 0);
        for (int nb = 0; nb != tmp; nb += 1) {
            store->game->first_mob = add_mob_link(store, store->game->first_mob
                                                , game_mob_missile, *pos);
            pos->x -= 100;
        }
        store->game->nb_mob_money -= tmp * 350;
    }
}

void game_spawn_mob(my_struct_t *store, int tmp)
{
    sfVector2f pos = {-40, 300};

    game_spawn_mob2(store, tmp, &pos);
    game_spawn_mob3(store, tmp, &pos);
    game_spawn_mob4(store, tmp, &pos);
}