/*
** EPITECH PROJECT, 2021
** make_game
** File description:
** file 1
*/

#include "../include/game.h"

void init_coord_loop(my_game *store)
{
    for (int nb = 0; nb < 4; nb += 1) {
        store->bg[nb]->pose.x = 0;
        store->bg[nb]->pose.y = 0;
        store->bg[nb]->poselp.x = 3840;
        store->bg[nb]->poselp.y = 0;
    }
}

void init_texture_loop(my_game *store)
{
    store->bg[0]->texture
        = sfTexture_createFromFile("src/texture/moon_and_sky.png", NULL);
    store->bg[1]->texture
        = sfTexture_createFromFile("src/texture/star.png", NULL);
    store->bg[2]->texture
        = sfTexture_createFromFile("src/texture/cloud_night.png", NULL);
    store->bg[3]->texture
        = sfTexture_createFromFile("src/texture/ground.png", NULL);
}

void create_parallax(my_game *store)
{
    for (int nb = 0; nb < 4; nb += 1) {
        store->bg[nb] = malloc(sizeof(parallax_t));
    }
    store->bg[0]->backgr = BACKGROUND;
    store->bg[1]->backgr = THIRD_GROUND;
    store->bg[2]->backgr = SECOND_GROUND;
    store->bg[3]->backgr = FOREGROUND;
    init_coord_loop(store);
    init_texture_loop(store);
    for (int nb = 0; nb < 4; nb += 1) {
        store->bg[nb]->sprite = sfSprite_create();
        store->bg[nb]->spritelp = sfSprite_create();
        sfSprite_setTexture(store->bg[nb]->sprite
            , store->bg[nb]->texture, sfTrue);
        sfSprite_setTexture(store->bg[nb]->spritelp
            , store->bg[nb]->texture, sfTrue);
    }
}

void destroy_parallax(my_game *store)
{
    for (int nb = 0; nb < 4; nb += 1) {
        sfSprite_destroy(store->bg[nb]->sprite);
        sfSprite_destroy(store->bg[nb]->spritelp);
        sfTexture_destroy(store->bg[nb]->texture);
        free(store->bg[nb]);
    }
}