/*
** EPITECH PROJECT, 2021
** move_sprite
** File description:
** file 1
*/

#include "../include/game.h"

void move_sprite_bg(my_game *store)
{
    store->bg[0]->pose.x -= 1;
    store->bg[0]->poselp.x -= 1;
    store->bg[1]->pose.x -= 2;
    store->bg[1]->poselp.x -= 2;
    store->bg[2]->pose.x -= 3;
    store->bg[2]->poselp.x -= 3;
    store->bg[3]->pose.x -= 4;
    store->bg[3]->poselp.x -= 4;
    for (int nb = 0; nb < 4; nb += 1) {
        if (store->bg[nb]->pose.x <= -3840)
            store->bg[nb]->pose.x = 3840;
        if (store->bg[nb]->poselp.x <= -3840)
            store->bg[nb]->poselp.x = 3840;
        sfSprite_setPosition(store->bg[nb]->sprite, store->bg[nb]->pose);
        sfSprite_setPosition(store->bg[nb]->spritelp, store->bg[nb]->poselp);
    }
}

void move_sprite_mob_and_player(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
        tmp->pose.x -= 4;
        sfSprite_setPosition(tmp->sprite, tmp->pose);
        tmp = tmp->next;
    }
    sfSprite_setPosition(store->player->sprite, store->player->pose);

}

void move_sprite(my_game *store)
{
    move_sprite_bg(store);
    move_sprite_mob_and_player(store);
    verif_win(store);
}