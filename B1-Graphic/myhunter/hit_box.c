/*
** EPITECH PROJECT, 2020
** hit_box
** File description:
** file 1
*/

#include "include/game.h"

void hit_box_mob_type_1(my_game *store, int x, int y)
{
    sfVector2f ctp;

    ctp = sfSprite_getPosition(store->sprite->spt1);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 1);
    ctp = sfSprite_getPosition(store->sprite->spt2);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 2);
    ctp = sfSprite_getPosition(store->sprite->spt3);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 3);
    ctp = sfSprite_getPosition(store->sprite->spt4);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 4);
}

void hit_box_mob_type_2(my_game *store, int x, int y)
{
    sfVector2f ctp;

    ctp = sfSprite_getPosition(store->sprite->spt5);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 5);
    ctp = sfSprite_getPosition(store->sprite->spt6);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 6);
    ctp = sfSprite_getPosition(store->sprite->spt7);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 7);
    ctp = sfSprite_getPosition(store->sprite->spt8);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 8);
}

void hit_box_mob_type_3(my_game *store, int x, int y)
{
    sfVector2f ctp;

    ctp = sfSprite_getPosition(store->sprite->spt9);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 9);
    ctp = sfSprite_getPosition(store->sprite->spt10);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 10);
    ctp = sfSprite_getPosition(store->sprite->spt11);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 11);
    ctp = sfSprite_getPosition(store->sprite->spt12);
    if ((x >= ctp.x && x <= (ctp.x + 34)) && (y >= ctp.y && y <= (ctp.y + 34)))
        sprite_touch(store, 12);
}

void hit_box_mob_type_4(my_game *store, int x, int y)
{
    sfVector2f ctp;

    ctp = sfSprite_getPosition(store->sprite->spt13);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 13);
    ctp = sfSprite_getPosition(store->sprite->spt14);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 14);
    ctp = sfSprite_getPosition(store->sprite->spt15);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 15);
    ctp = sfSprite_getPosition(store->sprite->spt16);
    if ((x >= ctp.x && x <= (ctp.x + 64)) && (y >= ctp.y && y <= (ctp.y + 60)))
        sprite_touch(store, 16);
}