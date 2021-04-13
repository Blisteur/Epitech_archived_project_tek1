/*
** EPITECH PROJECT, 2020
** score
** File description:
** file 1
*/

#include "include/game.h"

void verif_score_adv(my_game *store)
{
    if (store->score->score == 20 && store->score->lock_score == 3) {
        sfSprite_setPosition(store->sprite->spt9, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt10, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    if (store->score->score == 30 && store->score->lock_score == 4) {
        sfSprite_setPosition(store->sprite->spt11, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt12, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    if (store->score->score == 42 && store->score->lock_score == 5) {
        sfSprite_setPosition(store->sprite->spt13, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt14, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    if (store->score->score == 56 && store->score->lock_score == 6) {
        sfSprite_setPosition(store->sprite->spt15, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt16, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
}

void move_by_score(my_game *store)
{
    if (store->score->score == 50)
        store->timer->t_in_ms = 90000;
    if (store->score->score == 100)
        store->timer->t_in_ms = 80000;
    if (store->score->score == 150)
        store->timer->t_in_ms = 70000;
    if (store->score->score == 200)
        store->timer->t_in_ms = 60000;
    if (store->score->score == 250)
        store->timer->t_in_ms = 50000;
    if (store->score->score == 300)
        store->timer->t_in_ms = 40000;
    if (store->score->score == 350)
        store->timer->t_in_ms = 30000;
    if (store->score->score == 400)
        store->timer->t_in_ms = 25974;
}

void verif_score(my_game *store)
{
    if (store->score->score == 2 && store->score->lock_score == 0) {
        sfSprite_setPosition(store->sprite->spt3, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt4, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    if (store->score->score == 6 && store->score->lock_score == 1) {
        sfSprite_setPosition(store->sprite->spt5, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt6, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    if (store->score->score == 12 && store->score->lock_score == 2) {
        sfSprite_setPosition(store->sprite->spt7, store->pose->init_pose_g);
        sfSprite_setPosition(store->sprite->spt8, store->pose->init_pose_d);
        store->score->lock_score += 1;
    }
    verif_score_adv(store);
    move_by_score(store);
}