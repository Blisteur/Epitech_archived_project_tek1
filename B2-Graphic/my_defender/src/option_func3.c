/*
** EPITECH PROJECT, 2021
** option func
** File description:
** file 2
*/

#include "my_defender.h"

void sound_vl_p(my_struct_t *store)
{
    store->settings->volume[1] += 1;
    if (store->settings->volume[1] > 100)
        store->settings->volume[1] = 100;
    store->settings->is_modified = 1;
    sfSound_setVolume(store->audio->click_sound
    , store->settings->volume[1]);
    settings_get_volume(store, store->menu->options);
}

void sound_vl_m(my_struct_t *store)
{
    store->settings->volume[1] -= 1;
    if (store->settings->volume[1] < 0)
        store->settings->volume[1] = 0;
    store->settings->is_modified = 1;
    sfSound_setVolume(store->audio->click_sound
    , store->settings->volume[1]);
    settings_get_volume(store, store->menu->options);
}