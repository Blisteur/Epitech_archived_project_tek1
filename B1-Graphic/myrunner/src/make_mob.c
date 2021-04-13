/*
** EPITECH PROJECT, 2021
** make mob
** File description:
** file 1
*/

#include "../include/game.h"

void make_mob_cactus(mob_t *tmp)
{
    if (tmp->mob == CACTUS_TYPE_1) {
        tmp->texture
        = sfTexture_createFromFile("src/texture/cactus_type_1.png", NULL);
        tmp->hit_box_bottom_right.x = 58;
        tmp->hit_box_bottom_right.y = 115;
        tmp->pose.y = 600;
    }
    if (tmp->mob == CACTUS_TYPE_2) {
        tmp->texture
        = sfTexture_createFromFile("src/texture/cactus_type_2.png", NULL);
        tmp->hit_box_bottom_right.x = 83;
        tmp->hit_box_bottom_right.y = 163;
        tmp->pose.y = 550;
    }
}

void make_mob_bird(mob_t *tmp, int nb)
{
    if (tmp->mob == BIRD) {
        tmp->texture
        = sfTexture_createFromFile("src/texture/bird_night.png", NULL);
        tmp->pose.y = random_height_bird(nb);
        tmp->rect.left = 0;
        tmp->rect.top = 0;
        tmp->rect.width = 150;
        tmp->rect.height = 130;
        tmp->rect_value = 150;
        tmp->rect_max = 300;
        tmp->hit_box_bottom_right.x = 120;
        tmp->hit_box_bottom_right.y = 100;
    }
}

void make_mob(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
        tmp->sprite = sfSprite_create();
        make_mob_cactus(tmp);
        make_mob_bird(tmp, nb);
        sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
        sfSprite_setPosition(tmp->sprite, tmp->pose);
        tmp = tmp->next;
    }
}