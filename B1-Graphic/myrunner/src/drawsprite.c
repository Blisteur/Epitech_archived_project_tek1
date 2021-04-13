/*
** EPITECH PROJECT, 2020
** drawsprite
** File description:
** file 1
*/

#include "../include/game.h"

void drawsprite(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    if (store->mode == MODE_MENU)
        sfRenderWindow_drawSprite(store->win, store->menu->sprite, NULL);
    if (store->mode == MODE_GAME) {
        for (int nb = 0; nb < 4; nb += 1) {
            sfRenderWindow_drawSprite(store->win
                , store->bg[nb]->sprite, NULL);
            sfRenderWindow_drawSprite(store->win
                , store->bg[nb]->spritelp, NULL);
        }
        for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
            sfRenderWindow_drawSprite(store->win, tmp->sprite, NULL);
            tmp = tmp->next;
        }
        sfRenderWindow_drawSprite(store->win, store->player->sprite, NULL);
        sfRenderWindow_drawText(store->win, store->score->hi_text, NULL);
    }
}