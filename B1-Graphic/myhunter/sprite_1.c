/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** file 1
*/

#include "include/game.h"

void drawsprite(my_game *store)
{
    sfRenderWindow_drawSprite(store->win, store->sprite->sptbk, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt1, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt2, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt3, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt4, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt5, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt6, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt7, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt8, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt9, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt10, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt11, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt12, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt13, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt14, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt15, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->spt16, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->lf1, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->lf2, NULL);
    sfRenderWindow_drawSprite(store->win, store->sprite->lf3, NULL);
}

void set_pose_sprite(my_game *store)
{
    sfVector2f init;

    init.x = -100;
    init.y = -100;
    sfSprite_setPosition(store->sprite->spt1, init);
    sfSprite_setPosition(store->sprite->spt2, init);
    sfSprite_setPosition(store->sprite->spt3, init);
    sfSprite_setPosition(store->sprite->spt4, init);
    sfSprite_setPosition(store->sprite->spt5, init);
    sfSprite_setPosition(store->sprite->spt6, init);
    sfSprite_setPosition(store->sprite->spt7, init);
    sfSprite_setPosition(store->sprite->spt8, init);
    sfSprite_setPosition(store->sprite->spt9, init);
    sfSprite_setPosition(store->sprite->spt10, init);
    sfSprite_setPosition(store->sprite->spt11, init);
    sfSprite_setPosition(store->sprite->spt12, init);
    sfSprite_setPosition(store->sprite->spt13, init);
    sfSprite_setPosition(store->sprite->spt14, init);
    sfSprite_setPosition(store->sprite->spt15, init);
    sfSprite_setPosition(store->sprite->spt16, init);
}

void create_sprite(my_game *store)
{
    store->sprite->sptbk = sfSprite_create();
    store->sprite->spt1 = sfSprite_create();
    store->sprite->spt2 = sfSprite_create();
    store->sprite->spt3 = sfSprite_create();
    store->sprite->spt4 = sfSprite_create();
    store->sprite->spt5 = sfSprite_create();
    store->sprite->spt6 = sfSprite_create();
    store->sprite->spt7 = sfSprite_create();
    store->sprite->spt8 = sfSprite_create();
    store->sprite->spt9 = sfSprite_create();
    store->sprite->spt10 = sfSprite_create();
    store->sprite->spt11 = sfSprite_create();
    store->sprite->spt12 = sfSprite_create();
    store->sprite->spt13 = sfSprite_create();
    store->sprite->spt14 = sfSprite_create();
    store->sprite->spt15 = sfSprite_create();
    store->sprite->spt16 = sfSprite_create();
    store->sprite->lf1 = sfSprite_create();
    store->sprite->lf2 = sfSprite_create();
    store->sprite->lf3 = sfSprite_create();
}

void destroy_sprite(my_game *store)
{
    sfSprite_destroy(store->sprite->spt1);
    sfSprite_destroy(store->sprite->spt2);
    sfSprite_destroy(store->sprite->spt3);
    sfSprite_destroy(store->sprite->spt4);
    sfSprite_destroy(store->sprite->spt5);
    sfSprite_destroy(store->sprite->spt6);
    sfSprite_destroy(store->sprite->spt7);
    sfSprite_destroy(store->sprite->spt8);
    sfSprite_destroy(store->sprite->spt9);
    sfSprite_destroy(store->sprite->spt10);
    sfSprite_destroy(store->sprite->spt11);
    sfSprite_destroy(store->sprite->spt12);
    sfSprite_destroy(store->sprite->spt13);
    sfSprite_destroy(store->sprite->spt14);
    sfSprite_destroy(store->sprite->spt15);
    sfSprite_destroy(store->sprite->spt16);
    sfSprite_destroy(store->sprite->sptbk);
}

void set_sprite_rect(my_game *store)
{
    sfSprite_setTextureRect(store->sprite->spt1, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt2, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt3, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt4, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt5, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt6, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt7, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt8, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt9, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt10, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt11, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt12, store->rect->rect1);
    sfSprite_setTextureRect(store->sprite->spt13, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt14, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt15, store->rect->rect2);
    sfSprite_setTextureRect(store->sprite->spt16, store->rect->rect2);
}