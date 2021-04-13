/*
** EPITECH PROJECT, 2021
** audio run
** File description:
** file 1
*/

#include "my_defender.h"

void audio_run_hurt(my_struct_t *store)
{
    sfSound_play(store->audio->hurt_sound);
}

void audio_run_click(my_struct_t *store)
{
    sfSound_play(store->audio->click_sound);
}

void audio_run_place_tower(my_struct_t *store)
{
    sfSound_play(store->audio->place_tower_sound);
}