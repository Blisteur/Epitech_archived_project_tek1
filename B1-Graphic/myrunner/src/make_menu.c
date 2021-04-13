/*
** EPITECH PROJECT, 2021
** init game
** File description:
** file 1
*/

#include "../include/game.h"

void init_hit_box_boutton(menu_t *menu)
{
    menu->hit_box_top_left[0].x = 707;
    menu->hit_box_top_left[0].y = 384;
    menu->hit_box_bottom_right[0].x = 790;
    menu->hit_box_bottom_right[0].y = 401;
    menu->hit_box_top_left[1].x = 707;
    menu->hit_box_top_left[1].y = 404;
    menu->hit_box_bottom_right[1].x = 767;
    menu->hit_box_bottom_right[1].y = 421;
    menu->hit_box_top_left[2].x = 707;
    menu->hit_box_top_left[2].y = 427;
    menu->hit_box_bottom_right[2].x = 736;
    menu->hit_box_bottom_right[2].y = 440;
    menu->hit_box_top_left[3].x = 1875;
    menu->hit_box_top_left[3].y = 0;
    menu->hit_box_bottom_right[3].x = 1919;
    menu->hit_box_bottom_right[3].y = 28;
}

menu_t *make_menu(menu_t *menu)
{
    menu = malloc(sizeof(menu_t));
    menu->last = 0;
    menu->touch = 0;
    menu->pose.x = 0;
    menu->pose.y = 0;
    menu->texture[0] =
        sfTexture_createFromFile("src/texture/menu.png", NULL);
    menu->texture[1] =
        sfTexture_createFromFile("src/texture/menu_highlight_1.png", NULL);
    menu->texture[2] =
        sfTexture_createFromFile("src/texture/menu_highlight_2.png", NULL);
    menu->texture[3] =
        sfTexture_createFromFile("src/texture/menu_highlight_3.png", NULL);
    menu->texture[4] =
        sfTexture_createFromFile("src/texture/menu_highlight_4.png", NULL);
    menu->texture[5] = NULL;
    init_hit_box_boutton(menu);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->texture[0], sfTrue);
    return (menu);
}

int menu_boutton_scan(sfVector2i highlight, my_game *store)
{
    for (int nb = 0; nb < 4; nb += 1) {
        if (highlight.x > store->menu->hit_box_top_left[nb].x
        && highlight.y > store->menu->hit_box_top_left[nb].y
        && highlight.x < store->menu->hit_box_bottom_right[nb].x
        && highlight.y < store->menu->hit_box_bottom_right[nb].y) {
            store->menu->last = nb + 1;
            return (nb + 1);
        }
    }
    if (store->menu->last != 0) {
        store->menu->last = 0;
        return (0);
    }
    return (-1);
}

void menu_boutton_touch(my_game *store)
{
    int tmp = -1;
    int x = store->evt.mouseButton.x;
    int y = store->evt.mouseButton.y;

    for (int nb = 0; nb < 4; nb += 1) {
        if (x > store->menu->hit_box_top_left[nb].x
        && y > store->menu->hit_box_top_left[nb].y
        && x < store->menu->hit_box_bottom_right[nb].x
        && y < store->menu->hit_box_bottom_right[nb].y) {
            tmp = nb;
        }
    }
    if (tmp == 0)
        store->mode = MODE_GAME;
    if (tmp == 2 || tmp == 3)
        sfRenderWindow_close(store->win);
}

void destroy_menu(my_game *store)
{
    sfTexture_destroy(store->menu->texture[0]);
    sfTexture_destroy(store->menu->texture[1]);
    sfTexture_destroy(store->menu->texture[2]);
    sfTexture_destroy(store->menu->texture[3]);
    sfTexture_destroy(store->menu->texture[4]);
    sfSprite_destroy(store->menu->sprite);
    free(store->menu);
}