/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** file 2
*/

#include "include/game.h"

void sprite_touch_adv(my_game *store, int nb)
{
    if (nb == 9)
        sfSprite_setPosition(store->sprite->spt9, random_pose(1));
    if (nb == 10)
        sfSprite_setPosition(store->sprite->spt10, random_pose(2));
    if (nb == 11)
        sfSprite_setPosition(store->sprite->spt11, random_pose(1));
    if (nb == 12)
        sfSprite_setPosition(store->sprite->spt12, random_pose(2));
    if (nb == 13)
        sfSprite_setPosition(store->sprite->spt13, random_pose(1));
    if (nb == 14)
        sfSprite_setPosition(store->sprite->spt14, random_pose(2));
    if (nb == 15)
        sfSprite_setPosition(store->sprite->spt15, random_pose(1));
    if (nb == 16)
        sfSprite_setPosition(store->sprite->spt16, random_pose(2));
}

void sprite_touch(my_game *store, int nb)
{
    store->score->score += 1;
    if (nb == 1)
        sfSprite_setPosition(store->sprite->spt1, random_pose(1));
    if (nb == 2)
        sfSprite_setPosition(store->sprite->spt2, random_pose(2));
    if (nb == 3)
        sfSprite_setPosition(store->sprite->spt3, random_pose(1));
    if (nb == 4)
        sfSprite_setPosition(store->sprite->spt4, random_pose(2));
    if (nb == 5)
        sfSprite_setPosition(store->sprite->spt5, random_pose(1));
    if (nb == 6)
        sfSprite_setPosition(store->sprite->spt6, random_pose(2));
    if (nb == 7)
        sfSprite_setPosition(store->sprite->spt7, random_pose(1));
    if (nb == 8)
        sfSprite_setPosition(store->sprite->spt8, random_pose(2));
    sprite_touch_adv(store, nb);
}

void move_sprite_by_score1(my_game *store)
{
    if (store->score->score >= 2) {
        sfSprite_move(store->sprite->spt3, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt4, store->pose->move_pose_g);
    }
    if (store->score->score >= 6) {
        sfSprite_move(store->sprite->spt5, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt6, store->pose->move_pose_g);
    }
    if (store->score->score >= 12) {
        sfSprite_move(store->sprite->spt7, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt8, store->pose->move_pose_g);
    }
}

void move_sprite_by_score2(my_game *store)
{
    if (store->score->score >= 20) {
        sfSprite_move(store->sprite->spt9, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt10, store->pose->move_pose_g);
    }
    if (store->score->score >= 30) {
        sfSprite_move(store->sprite->spt11, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt12, store->pose->move_pose_g);
    }
    if (store->score->score >= 42) {
        sfSprite_move(store->sprite->spt13, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt14, store->pose->move_pose_g);
    }
    if (store->score->score >= 56) {
        sfSprite_move(store->sprite->spt15, store->pose->move_pose_d);
        sfSprite_move(store->sprite->spt16, store->pose->move_pose_g);
    }
}

void move_sprite(my_game *store)
{
    sfVector2f max = {0, 0};

    sfSprite_move(store->sprite->spt1, store->pose->move_pose_d);
    sfSprite_move(store->sprite->spt2, store->pose->move_pose_g);
    move_sprite_by_score1(store);
    move_sprite_by_score2(store);
    sprite_out_mob_1(store, max);
    sprite_out_mob_2(store, max);
    sprite_out_mob_3(store, max);
    sprite_out_mob_4(store, max);
}