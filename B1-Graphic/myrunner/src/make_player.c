/*
** EPITECH PROJECT, 2021
** make_player
** File description:
** file 1
*/

#include "../include/game.h"

void init_value_player(my_game *store)
{
    store->player->player_jump = 0;
    store->player->player_jump_speed = 0.5;
    store->player->pose.x = 20;
    store->player->pose.y = 550;
    store->player->hit_box_bottom_right.x = 134;
    store->player->hit_box_bottom_right.y = 143;
    store->player->rect.width = 144;
    store->player->rect.height = 153;
    store->player->rect.top = 0;
    store->player->rect.left = 0;
    store->player->rect_max = 288;
    store->player->rect_value = 144;
}

void create_player(my_game *store)
{
    store->player = malloc(sizeof(player_t));
    init_value_player(store);
    store->player->texture[0]
        = sfTexture_createFromFile("src/texture/dino_night.png", NULL);
    store->player->texture[1]
        = sfTexture_createFromFile("src/texture/dino_jump_night.png", NULL);
    store->player->texture[2] = NULL;
    store->player->sprite = sfSprite_create();
    sfSprite_setTexture(store->player->sprite
        , store->player->texture[0], sfTrue);
    sfSprite_setTextureRect(store->player->sprite, store->player->rect);
    sfSprite_setPosition(store->player->sprite, store->player->pose);
}

void jump_player(my_game *store)
{
    sfTime tmp = {0};

    if (store->player->pose.y == 550) {
        sfMusic_setPlayingOffset(store->sound->jump, tmp);
        sfMusic_play(store->sound->jump);
        store->player->player_jump = 1;
        sfSprite_setTexture(store->player->sprite
            , store->player->texture[1], sfFalse);
    }
}

void jump_player_statue(my_game *store)
{
    if (store->player->player_jump == 1) {
        store->player->pose.y -= store->player->player_jump_speed;
        store->player->player_jump_speed -= 0.0005;
    }
    if (store->player->player_jump == 3) {
        store->player->pose.y += store->player->player_jump_speed;
        store->player->player_jump_speed += 0.0005;
    }
    if (store->player->player_jump == 2) {
        store->player->player_jump = 3;
        store->timer->gravity = 500;
    }
}

void destroy_player(my_game *store)
{
    sfTexture_destroy(store->player->texture[0]);
    sfTexture_destroy(store->player->texture[1]);
    sfSprite_destroy(store->player->sprite);
    free(store->player);
}