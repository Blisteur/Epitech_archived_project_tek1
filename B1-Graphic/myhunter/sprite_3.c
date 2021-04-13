/*
** EPITECH PROJECT, 2020
** sprite out mob
** File description:
** file 3
*/

#include "include/game.h"

void sprite_out_mob_1(my_game *store, sfVector2f max)
{
    max = sfSprite_getPosition(store->sprite->spt1);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt1, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt2);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt2, store->pose->init_pose_d);
    }
    max = sfSprite_getPosition(store->sprite->spt3);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt3, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt4);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt4, store->pose->init_pose_d);
    }
}

void sprite_out_mob_2(my_game *store, sfVector2f max)
{
    max = sfSprite_getPosition(store->sprite->spt5);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt5, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt6);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt6, store->pose->init_pose_d);
    }
    max = sfSprite_getPosition(store->sprite->spt7);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt7, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt8);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt8, store->pose->init_pose_d);
    }
}

void sprite_out_mob_3(my_game *store, sfVector2f max)
{
    max = sfSprite_getPosition(store->sprite->spt9);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt9, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt10);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt10, store->pose->init_pose_d);
    }
    max = sfSprite_getPosition(store->sprite->spt11);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt11, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt12);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt12, store->pose->init_pose_d);
    }
}

void sprite_out_mob_4(my_game *store, sfVector2f max)
{
    max = sfSprite_getPosition(store->sprite->spt13);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt13, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt14);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt14, store->pose->init_pose_d);
    }
    max = sfSprite_getPosition(store->sprite->spt15);
    if (max.x == 1960) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt15, store->pose->init_pose_g);
    }
    max = sfSprite_getPosition(store->sprite->spt16);
    if (max.x == -40) {
        verif_life(store);
        sfSprite_setPosition(store->sprite->spt16, store->pose->init_pose_d);
    }
}