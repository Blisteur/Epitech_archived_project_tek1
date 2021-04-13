/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tower_menu_stop.c
*/

#include "my_defender.h"

void change_mouse_pos(my_struct_t *store, select_t *select)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->win);
    sfVector2f temp = sfRenderWindow_mapPixelToCoords(store->win, mouse, NULL);
    sfVector2f stop = {temp.x - 32, temp.y - 64};

    select->pos.left = temp.x - 32;
    select->pos.top = temp.y - 64;
    sfSprite_setPosition(select->sprite, temp);
    sfRectangleShape_setPosition(select->stop, stop);
}

void selector_stop(select_t *select)
{
    sfVector2f temp = {-400, -400};

    sfSprite_setPosition(select->sprite, temp);
    sfRectangleShape_setPosition(select->stop, temp);
    select->selected = 0;
}

void update_stop(select_t *select)
{
    sfVector2f big = {32, 32};
    sfVector2f small = {16, 32};

    if (select->selected == -8) {
        sfRectangleShape_setSize(select->stop, big);
        select->pos.width = 128;
    }
    else {
        sfRectangleShape_setSize(select->stop, small);
        select->pos.width = 64;
    }
}

sfRectangleShape *load_stop(void)
{
    sfRectangleShape *stop = sfRectangleShape_create();
    sfUint8 ints[4] = {255, 0, 0, 128};
    sfColor red = sfColor_fromRGBA(ints[0], ints[1], ints[2], ints[3]);
    sfVector2f pos = {-400, -400};
    sfVector2f size = {16, 32};
    sfVector2f scale = {4, 4};

    sfRectangleShape_setScale(stop, scale);
    sfRectangleShape_setFillColor(stop, red);
    sfRectangleShape_setPosition(stop, pos);
    sfRectangleShape_setSize(stop, size);
    return (stop);
}