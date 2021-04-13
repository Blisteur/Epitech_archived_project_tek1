/*
** EPITECH PROJECT, 2021
** event_per_mode
** File description:
** file 1
*/

#include "../include/game.h"

void events_per_mode(my_game *store)
{
    sfVector2i highlight = {0};

    if (store->mode == MODE_MENU) {
        highlight = sfMouse_getPositionRenderWindow(store->win);
        store->menu->touch = menu_boutton_scan(highlight, store);
        if (store->menu->touch != -1)
            sfSprite_setTexture(store->menu->sprite
            , store->menu->texture[store->menu->touch], sfTrue);
    }
    if (store->mode == MODE_GAME)
        verif_hit_box(store);
    if (store->mode == MODE_END && store->timer->time_freeze != 0)
        game_over(store);
}