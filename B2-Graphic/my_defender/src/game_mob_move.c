/*
** EPITECH PROJECT, 2021
** game mob move
** File description:
** file 1
*/

#include "my_defender.h"

static void game_mob_move_up(game_mob_link_t *tmp)
{
    tmp->rec.top = 64;
    tmp->pos.y -= tmp->speed * 1;
}

static void game_mob_move_down(game_mob_link_t *tmp)
{
    tmp->rec.top = 32;
    tmp->pos.y += tmp->speed * 1;
}

static void game_mob_move_right(game_mob_link_t *tmp)
{
    tmp->rec.top = 0;
    tmp->pos.x += tmp->speed * 1;
}

static void path_finding(game_mob_link_t *tmp)
{
    if (tmp->pos.x >= 620 && tmp->pos.x <= 621 && tmp->pos.y < 675) {
        tmp->pos.x = 620;
        game_mob_move_down(tmp);
    }
    if (tmp->pos.y >= 675 && tmp->pos.y <= 676 && tmp->pos.x < 1000) {
        tmp->pos.y = 675;
        game_mob_move_right(tmp);
    }
    if (tmp->pos.x >= 1000 && tmp->pos.x <= 1001 && tmp->pos.y > 400) {
        tmp->pos.x = 1000;
        game_mob_move_up(tmp);
    }
    if (tmp->pos.y >= 400 && tmp->pos.y <= 401
        && tmp->pos.x < 1400 && tmp->pos.x >= 1000) {
        tmp->pos.y = 400;
        game_mob_move_right(tmp);
    }
}

void game_mob_move(my_struct_t *store)
{
    game_mob_link_t *tmp = store->game->first_mob;

    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        if (tmp->pos.y == 300 && tmp->pos.x < 235) {
            game_mob_move_right(tmp);
        }
        if (tmp->pos.x >= 235 && tmp->pos.x <= 236 && tmp->pos.y > 110) {
            tmp->pos.x = 235;
            game_mob_move_up(tmp);
        }
        if (tmp->pos.y <= 110 && tmp->pos.y >= 109 && tmp->pos.x < 620) {
            tmp->pos.y = 110;
            game_mob_move_right(tmp);
        }
        path_finding(tmp);
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
    verif_life(store);
}