/*
** EPITECH PROJECT, 2021
** game_over
** File description:
** file 1
*/

#include "../include/game.h"

void init_game_over(my_game *store)
{
    store->game_over = malloc(sizeof(game_over_t));
    store->game_over->sprite = sfSprite_create();
    store->game_over->texture[0]
    = sfTexture_createFromFile("src/texture/game_over_hud_night.png", NULL);
    store->game_over->texture[1]
    = sfTexture_createFromFile("src/texture/game_over_hud_day.png", NULL);
    store->game_over->pose.x = 0;
    store->game_over->pose.y = 0;
    sfSprite_setTexture(store->game_over->sprite
        , store->game_over->texture[0], sfTrue);
}

void destroy_game_over(my_game *store)
{
    sfSprite_destroy(store->game_over->sprite);
    sfTexture_destroy(store->game_over->texture[0]);
    sfTexture_destroy(store->game_over->texture[1]);
    free(store->game_over);
}

void game_over_restart(my_game *store)
{
    mob_t *tmp = store->mob_list_first;
    char reset_score[] = "00000";

    make_high_score(store);
    store->score->nb_co_score = 0;
    my_strcpy(store->score->text + 11, reset_score);
    while (store->nb_link_mob != 0) {
        remove_link_mob(store, tmp);
        tmp = store->mob_list_first;
    }
    remake_map(store);
    store->mode = MODE_GAME;
}

void game_over_event(my_game *store)
{
    if (((store->evt.type == sfEvtMouseButtonPressed
        && store->evt.mouseButton.button == 0)
        || (store->evt.key.code == sfKeySpace
        && store->evt.type == sfEvtKeyReleased))
        && store->mode == MODE_END)
        game_over_restart(store);
    if (store->mode != MODE_MENU
        && store->evt.key.code == sfKeyEnter
        && store->evt.type == sfEvtKeyReleased)
        game_over_restart(store);
}

void game_over(my_game *store)
{
    sfTime tmp = {0};

    sfRenderWindow_drawSprite(store->win, store->game_over->sprite, NULL);
    store->timer->time_freeze = 0;
    sfMusic_pause(store->sound->music);
    sfMusic_setPlayingOffset(store->sound->dead, tmp);
    sfMusic_play(store->sound->dead);
}