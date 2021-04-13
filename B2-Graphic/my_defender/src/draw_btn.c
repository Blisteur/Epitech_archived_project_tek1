/*
** EPITECH PROJECT, 2021
** draw btn
** File description:
** file 1
*/

#include "my_defender.h"

void draw_btn(my_struct_t *store, button_t *btn)
{
    sfRenderWindow_drawSprite(store->win, btn->sprite, NULL);
    sfRenderWindow_drawText(store->win, btn->text, NULL);
}