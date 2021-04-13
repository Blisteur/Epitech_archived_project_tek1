/*
** EPITECH PROJECT, 2020
** texture.c
** File description:
** file 1
*/

#include "include/game.h"

void create_texture(my_game *store)
{
    store->texture->txtbk = sfTexture_createFromFile("src/bg.png", NULL);
    store->texture->txt1 = sfTexture_createFromFile("src/txt1.png", NULL);
    store->texture->txt2 = sfTexture_createFromFile("src/txt1r.png", NULL);
    store->texture->txt3 = sfTexture_createFromFile("src/txt2.png", NULL);
    store->texture->txt4 = sfTexture_createFromFile("src/txt2r.png", NULL);
    store->texture->txt5 = sfTexture_createFromFile("src/txt3.png", NULL);
    store->texture->txt6 = sfTexture_createFromFile("src/txt3r.png", NULL);
    store->texture->txt7 = sfTexture_createFromFile("src/txt4.png", NULL);
    store->texture->txt8 = sfTexture_createFromFile("src/txt4r.png", NULL);
    store->texture->lf1 = sfTexture_createFromFile("src/life1.png", NULL);
    store->texture->lf2 = sfTexture_createFromFile("src/life2.png", NULL);
    store->texture->lf3 = sfTexture_createFromFile("src/life3.png", NULL);
    store->texture->lf1_d = sfTexture_createFromFile("src/life1_d.png", NULL);
    store->texture->lf2_d = sfTexture_createFromFile("src/life2_d.png", NULL);
    store->texture->lf3_d = sfTexture_createFromFile("src/life3_d.png", NULL);
}

void set_texture(my_game *store)
{
    sfSprite_setTexture(store->sprite->spt1, store->texture->txt1, sfTrue);
    sfSprite_setTexture(store->sprite->spt2, store->texture->txt2, sfTrue);
    sfSprite_setTexture(store->sprite->spt3, store->texture->txt1, sfTrue);
    sfSprite_setTexture(store->sprite->spt4, store->texture->txt2, sfTrue);
    sfSprite_setTexture(store->sprite->spt5, store->texture->txt3, sfTrue);
    sfSprite_setTexture(store->sprite->spt6, store->texture->txt4, sfTrue);
    sfSprite_setTexture(store->sprite->spt7, store->texture->txt3, sfTrue);
    sfSprite_setTexture(store->sprite->spt8, store->texture->txt4, sfTrue);
    sfSprite_setTexture(store->sprite->spt9, store->texture->txt5, sfTrue);
    sfSprite_setTexture(store->sprite->spt10, store->texture->txt6, sfTrue);
    sfSprite_setTexture(store->sprite->spt11, store->texture->txt5, sfTrue);
    sfSprite_setTexture(store->sprite->spt12, store->texture->txt6, sfTrue);
    sfSprite_setTexture(store->sprite->spt13, store->texture->txt7, sfTrue);
    sfSprite_setTexture(store->sprite->spt14, store->texture->txt8, sfTrue);
    sfSprite_setTexture(store->sprite->spt15, store->texture->txt7, sfTrue);
    sfSprite_setTexture(store->sprite->spt16, store->texture->txt8, sfTrue);
}

void set_texture_rect(my_game *store)
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

void destroy_texture(my_game *store)
{
    sfTexture_destroy(store->texture->txt1);
    sfTexture_destroy(store->texture->txt2);
    sfTexture_destroy(store->texture->txt3);
    sfTexture_destroy(store->texture->txt4);
    sfTexture_destroy(store->texture->txt5);
    sfTexture_destroy(store->texture->txt6);
    sfTexture_destroy(store->texture->txt7);
    sfTexture_destroy(store->texture->txt8);
    sfTexture_destroy(store->texture->txtbk);
}