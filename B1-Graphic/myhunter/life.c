/*
** EPITECH PROJECT, 2020
** life
** File description:
** file 1
*/

#include "include/game.h"

void set_life_sprite(my_game *store)
{
    sfVector2f init = {949, 950};

    sfSprite_setPosition(store->sprite->lf2, init);
    init.x =  919;
    sfSprite_setPosition(store->sprite->lf1, init);
    init.x = 991;
    sfSprite_setPosition(store->sprite->lf3, init);
}

void set_life_texture(my_game *store)
{
    sfSprite_setTexture(store->sprite->lf1, store->texture->lf1, sfTrue);
    sfSprite_setTexture(store->sprite->lf2, store->texture->lf2, sfTrue);
    sfSprite_setTexture(store->sprite->lf3, store->texture->lf3, sfTrue);
}

void destroy_life(my_game *store)
{
    sfTexture_destroy(store->texture->lf1);
    sfTexture_destroy(store->texture->lf2);
    sfTexture_destroy(store->texture->lf3);
    sfTexture_destroy(store->texture->lf1_d);
    sfTexture_destroy(store->texture->lf2_d);
    sfTexture_destroy(store->texture->lf3_d);
    sfSprite_destroy(store->sprite->lf1);
    sfSprite_destroy(store->sprite->lf2);
    sfSprite_destroy(store->sprite->lf3);
}

void verif_life(my_game *store)
{
    store->life -= 1;
    if (store->life == 2)
        sfSprite_setTexture(store->sprite->lf1, store->texture->lf1_d, sfTrue);
    if (store->life == 1)
        sfSprite_setTexture(store->sprite->lf2, store->texture->lf2_d, sfTrue);
    if (store->life == 0)
        sfSprite_setTexture(store->sprite->lf2, store->texture->lf2_d, sfTrue);
    if (store->life == 0) {
        my_printf("You lose !\n");
        sfRenderWindow_close(store->win);
    }
}