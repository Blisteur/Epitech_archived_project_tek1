/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** game_menu.c
*/

#include "my_defender.h"

void display_menu(struct my_struct_s *store)
{
    sfRenderWindow_drawSprite(store->win, store->menu->backsp, NULL);
    sfRenderWindow_drawText(store->win, store->menu->title, NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->quit->sprite, NULL);
    sfRenderWindow_drawText(store->win, store->menu->quit->text, NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->start->sprite, NULL);
    sfRenderWindow_drawText(store->win, store->menu->start->text, NULL);
    sfRenderWindow_drawText(store->win, store->score->hi_text, NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->settings->sprite, NULL);
    sfRenderWindow_drawText(store->win, store->menu->settings->text, NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->manual->sprite, NULL);
    sfRenderWindow_drawText(store->win, store->menu->manual->text, NULL);
    if (store->menu->options->active == 1)
        display_menu_settings(store->menu->options, store);
    if (store->menu->options->active == -1)
        sfRenderWindow_drawSprite(store->win, store->menu->howto, NULL);
}

int mouse_over_button(sfIntRect pos, my_struct_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->win);
    sfVector2f temp = sfRenderWindow_mapPixelToCoords(store->win, mouse, NULL);
    int x = temp.x;
    int y = temp.y;

    if (sfIntRect_contains(&pos, x, y) == 1)
        return (1);
    return (0);
}

void interact_with_button(struct button_s *btn, sfEvent evt, my_struct_t *stor)
{
    if (mouse_over_button(btn->pos, stor) == 1) {
        btn->rect.top = 16;
        if (evt.type == sfEvtMouseButtonPressed)
            btn->pressed = 1;
        if (btn->pressed == 1)
            btn->rect.top = 32;
        if (evt.type == sfEvtMouseButtonReleased && btn->pressed == 1) {
            btn->pressed = 0;
            audio_run_click(stor);
            btn->ptr(stor);
            return;
        }
    }
    else {
        btn->rect.top = 0;
        btn->pressed = 0;
    }
    sfSprite_setTextureRect(btn->sprite, btn->rect);
}