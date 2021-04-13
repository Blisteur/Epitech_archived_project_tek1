/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tower_menu_evt.c
*/

#include "my_defender.h"

void selector_pos(my_struct_t *store, select_t *select)
{
    change_mouse_pos(store, select);
    select->can_place = can_place_tower(select, store->game->towers);
    if (store->evt.type == sfEvtMouseButtonReleased) {
        if (select->can_place == 1) {
            add_tower(&store->game->towers->list, store->game->towers,
            store->game->select, store);
            update_money_txt(store, select->prices[select->selected *
            - 1 - 1], '-');
        }
        selector_stop(select);
    }
}

void update_selector(select_t *select)
{
    sfIntRect crop = set_intrect(16 * (select->selected - 1), 32, 16, 32);

    if (select->selected == 0)
        return;
    if (select->selected == 8) {
        sfSprite_setTexture(select->sprite, select->big, sfFalse);
        crop.left = 0;
        select->pos.width = 128;
        crop.width = 32;
    }
    else {
        sfSprite_setTexture(select->sprite, select->small, sfFalse);
        select->pos.width = 64;
    }
    sfSprite_setTextureRect(select->sprite, crop);
    select->selected = select->selected * -1;
    update_stop(select);
}

void click_selector(my_struct_t *store, select_t *select)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->win);
    sfVector2f temp = sfRenderWindow_mapPixelToCoords(store->win, mouse, NULL);

    if (store->evt.type != sfEvtMouseButtonPressed)
        return;
    if (temp.x < 1440)
        return;
    for (int a = 0; a != 8; a++) {
        if (sfIntRect_contains(&select->buy[a], temp.x, temp.y) == 1 &&
        store->game->nb_money >= select->prices[a]) {
            select->selected = a + 1;
            update_selector(select);
            return;
        }
    }
    return;
}