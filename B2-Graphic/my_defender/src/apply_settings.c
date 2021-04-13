/*
** EPITECH PROJECT, 2021
** apply settings
** File description:
** file 1
*/

#include "my_defender.h"

void apply_settings(my_struct_t *store)
{
    sfRenderWindow_destroy(store->win);
    if (store->settings->fullscreen == 0)
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_DEFENDER", sfResize | sfClose, NULL);
    else
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_DEFENDER", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(store->win, store->settings->fps);
    sfRenderWindow_setView(store->win, store->cam);
}