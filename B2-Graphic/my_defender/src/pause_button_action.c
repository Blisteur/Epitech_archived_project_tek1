/*
** EPITECH PROJECT, 2021
** pause button action
** File description:
** file 1
*/

#include "my_defender.h"

void pause_button_quit_to_menu(my_struct_t *store)
{
    store->game->mode = MODE_GAME;
    store->game->stop = 1;
}

void pause_button_resume(my_struct_t *store)
{
    store->game->mode = MODE_GAME;
    sfMusic_play(store->audio->master_music);
}

void pause_button_exit(my_struct_t *store)
{
    store->game->mode = MODE_GAME;
    sfRenderWindow_close(store->win);
    store->game->stop = 1;
}