/*
** EPITECH PROJECT, 2020
** rect
** File description:
** file 1
*/

#include "include/game.h"

void rect_init(my_game *store)
{
    store->rect->rect1.top = 0;
    store->rect->rect1.left = 0;
    store->rect->rect1.height = 33;
    store->rect->rect1.width = 33.5;
    store->rect->rect2.top = 0;
    store->rect->rect2.left = 0;
    store->rect->rect2.height = 60;
    store->rect->rect2.width = 63.75;
    store->pose->init_pose_g.x = -20;
    store->pose->init_pose_g.y = 800;
    store->pose->init_pose_d.x = 1940;
    store->pose->init_pose_d.y = 400;
    store->pose->move_pose_d.x = 10;
    store->pose->move_pose_d.y = 0;
    store->pose->move_pose_g.x = -10;
    store->pose->move_pose_g.y = 0;
}

void rect_move(my_game *store, sfIntRect *rect1, sfIntRect *rect2)
{
    rect1->left += 34;
    rect2->left += 64;
    if (rect1->left >= 134)
        rect1->left = 0;
    if (rect2->left >= 255)
        rect2->left = 0;
    set_sprite_rect(store);
}