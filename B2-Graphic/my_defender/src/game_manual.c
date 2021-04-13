/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-mydefender-hildebert.jeanjean
** File description:
** game_manual.c
*/

#include "my_defender.h"

void manual_button(my_struct_t *store)
{
    if (store->menu->options->active != -1)
        store->menu->options->active = -1;
    else
        store->menu->options->active = 0;
}

void load_manual(struct menu_s *menu)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {864, 0};

    menu->howtt = sfTexture_createFromFile("./sprites/manual.png", NULL);
    menu->howto = sfSprite_create();
    sfSprite_setTexture(menu->howto, menu->howtt, sfFalse);
    sfSprite_setPosition(menu->howto, pos);
    sfSprite_setScale(menu->howto, scale);
}