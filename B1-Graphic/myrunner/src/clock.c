/*
** EPITECH PROJECT, 2021
** clock
** File description:
** file 1
*/

#include "../include/game.h"

void cooldown_jump_player(my_game *store)
{
    store->timer->time_jump = sfClock_getElapsedTime(store->timer->clock_jump);
    if (store->timer->time_jump.microseconds >= store->timer->gravity) {
        for (int i = 0; i <
            (store->timer->time_jump.microseconds /
            store->timer->gravity); i += 1)
            jump_player_statue(store);
        sfClock_restart(store->timer->clock_jump);
    }
    if (store->player->pose.y <= random_height_jump()) {
        store->player->player_jump = 2;
        store->timer->gravity = 10000;
        store->player->player_jump_speed = 0.5;
    }
    if (store->player->pose.y >= 550) {
        store->player->player_jump = 0;
        store->player->pose.y = 550;
        store->player->player_jump_speed = 0.5;
        sfSprite_setTexture(store->player->sprite
            , store->player->texture[0], sfFalse);
    }
}

void timer_anim(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    store->timer->time_anim = sfClock_getElapsedTime(store->timer->clock_anim);
    if (store->timer->time_anim.microseconds >= 90000) {
        for (int i = 0; i <
            (store->timer->time_anim.microseconds / 90000); i += 1) {
            tmp = store->mob_list_first;
            for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
                rect_mob_move(tmp, &tmp->rect);
                tmp = tmp->next;
            }
            rect_player_move(store->player, &store->player->rect);
        }
        sfClock_restart(store->timer->clock_anim);
    }
}

void timer_move(my_game *store)
{
    store->timer->time_move = sfClock_getElapsedTime(store->timer->clock_move);
    if (store->timer->time_move.microseconds >= store->timer->t_in_ms) {
        for (int i = 0; i <
            (store->timer->time_move.microseconds /
            store->timer->t_in_ms); i += 1) {
            move_sprite(store);
        }
        sfClock_restart(store->timer->clock_move);
    }
}

void timer_score(my_game *store)
{
    store->timer->time_score
        = sfClock_getElapsedTime(store->timer->clock_score);
    if (store->timer->time_score.microseconds >= 100000) {
        for (int i = 0; i <
            (store->timer->time_score.microseconds /
            100000); i += 1) {
            score_actu(store, 11);
        }
        sfClock_restart(store->timer->clock_score);
    }
}

void timer(my_game *store)
{
    if (store->mode == MODE_GAME) {
        if (store->timer->time_freeze == 0) {
            sfClock_restart(store->timer->clock_anim);
            sfClock_restart(store->timer->clock_move);
            sfClock_restart(store->timer->clock_jump);
            sfClock_restart(store->timer->clock_score);
            sfMusic_play(store->sound->music);
            store->timer->time_freeze = 1;
        }
        timer_anim(store);
        timer_move(store);
        timer_score(store);
        cooldown_jump_player(store);
    }
    if (store->mode == MODE_PAUSE && store->timer->time_freeze != 0)
        make_pause(store);
}