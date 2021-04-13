/*
** EPITECH PROJECT, 2021
** hit_box
** File description:
** file 1
*/

#include "../include/game.h"

void verif_hit_box_top_left(my_game *store, mob_t *tmp)
{
    int p_x = store->player->pose.x;
    int p_y = store->player->pose.y;

    if (p_x > tmp->pose.x
    && p_y > tmp->pose.y
    && p_x < tmp->pose.x + tmp->hit_box_bottom_right.x
    && p_y < tmp->pose.y + tmp->hit_box_bottom_right.y)
        store->mode = MODE_END;
}

void verif_hit_box_top_right(my_game *store, mob_t *tmp)
{
    int p_x = store->player->pose.x + store->player->hit_box_bottom_right.x;
    int p_y = store->player->pose.y;

    if (p_x > tmp->pose.x
    && p_y > tmp->pose.y
    && p_x < tmp->pose.x + tmp->hit_box_bottom_right.x
    && p_y < tmp->pose.y + tmp->hit_box_bottom_right.y)
        store->mode = MODE_END;
}

void verif_hit_box_bottom_left(my_game *store, mob_t *tmp)
{
    int p_x = store->player->pose.x;
    int p_y = store->player->pose.y + store->player->hit_box_bottom_right.y;

    if (p_x > tmp->pose.x
    && p_y > tmp->pose.y
    && p_x < tmp->pose.x + tmp->hit_box_bottom_right.x
    && p_y < tmp->pose.y + tmp->hit_box_bottom_right.y)
        store->mode = MODE_END;
}

void verif_hit_box_bottom_right(my_game *store, mob_t *tmp)
{
    int p_x = store->player->pose.x + store->player->hit_box_bottom_right.x;
    int p_y = store->player->pose.y + store->player->hit_box_bottom_right.y;

    if (p_x > tmp->pose.x
    && p_y > tmp->pose.y
    && p_x < tmp->pose.x + tmp->hit_box_bottom_right.x
    && p_y < tmp->pose.y + tmp->hit_box_bottom_right.y)
        store->mode = MODE_END;
}

void verif_hit_box(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
        verif_hit_box_top_left(store, tmp);
        verif_hit_box_top_right(store, tmp);
        verif_hit_box_bottom_left(store, tmp);
        verif_hit_box_bottom_right(store, tmp);
        tmp = tmp->next;
    }
}