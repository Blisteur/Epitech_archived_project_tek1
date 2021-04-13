/*
** EPITECH PROJECT, 2021
** rect_move
** File description:
** file 1
*/

#include "../include/game.h"

void rect_mob_move(mob_t *tmp, sfIntRect *rect)
{
    if (tmp->mob == BIRD) {
        rect->left += tmp->rect_value;
        if (rect->left >= tmp->rect_max)
            rect->left = 0;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
}

void rect_player_move(player_t *player, sfIntRect *rect)
{
    rect->left += player->rect_value;
    if (rect->left >= player->rect_max)
        rect->left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
}