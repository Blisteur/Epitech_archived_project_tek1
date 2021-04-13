/*
** EPITECH PROJECT, 2021
** option func
** File description:
** file 2
*/

#include "my_defender.h"

void thirty_fps(my_struct_t *store)
{
    sfText_setColor(store->menu->options->thirty_fps->text, sfGreen);
    sfText_setColor(store->menu->options->sixty_fps->text, sfRed);
    store->settings->fps = 30;
    store->settings->is_modified = 1;
    apply_settings(store);
}

void sixty_fps(my_struct_t *store)
{
    sfText_setColor(store->menu->options->thirty_fps->text, sfRed);
    sfText_setColor(store->menu->options->sixty_fps->text, sfGreen);
    store->settings->fps = 60;
    store->settings->is_modified = 1;
    apply_settings(store);
}

void master_vl_p(my_struct_t *store)
{
    store->settings->volume[0] += 1;
    if (store->settings->volume[0] > 100)
        store->settings->volume[0] = 100;
    store->settings->is_modified = 1;
    sfMusic_setVolume(store->audio->master_music, store->settings->volume[0]);
    settings_get_volume(store, store->menu->options);
}

void master_vl_m(my_struct_t *store)
{
    store->settings->volume[0] -= 1;
    if (store->settings->volume[0] < 0)
        store->settings->volume[0] = 0;
    store->settings->is_modified = 1;
    sfMusic_setVolume(store->audio->master_music, store->settings->volume[0]);
    settings_get_volume(store, store->menu->options);
}