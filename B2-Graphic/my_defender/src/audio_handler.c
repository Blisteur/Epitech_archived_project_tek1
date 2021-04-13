/*
** EPITECH PROJECT, 2021
** audio_handler
** File description:
** file 1
*/

#include "my_defender.h"

void init_audio(my_struct_t *store)
{
    store->audio = malloc(sizeof(audio_t));

    store->audio->master_music
    = sfMusic_createFromFile("src/files/loop_music.ogg");
    store->audio->click_sound_buffer
    = sfSoundBuffer_createFromFile("src/files/click.ogg");
    store->audio->click_sound = sfSound_create();
    sfSound_setBuffer(store->audio->click_sound
    , store->audio->click_sound_buffer);
    sfSound_setVolume(store->audio->click_sound, store->settings->volume[1]);
    store->audio->hurt_sound = NULL;
    store->audio->place_tower_sound = NULL;
    sfMusic_play(store->audio->master_music);
    sfMusic_setLoop(store->audio->master_music, sfTrue);
    sfMusic_setVolume(store->audio->master_music, store->settings->volume[0]);
}

void destroy_audio(my_struct_t *store)
{
    sfMusic_destroy(store->audio->master_music);
    sfSoundBuffer_destroy(store->audio->click_sound_buffer);
    sfSound_destroy(store->audio->click_sound);
    free(store->audio);
}

void init_game_sound(my_struct_t *store)
{
    store->audio->hurt_sound_buffer
    = sfSoundBuffer_createFromFile("src/files/domage.ogg");
    store->audio->place_tower_sound_buffer
    = sfSoundBuffer_createFromFile("src/files/place_tour.ogg");
    store->audio->hurt_sound = sfSound_create();
    store->audio->place_tower_sound = sfSound_create();
    sfSound_setBuffer(store->audio->hurt_sound
    , store->audio->hurt_sound_buffer);
    sfSound_setBuffer(store->audio->place_tower_sound
    , store->audio->place_tower_sound_buffer);
    sfSound_setVolume(store->audio->hurt_sound, store->settings->volume[1]);
    sfSound_setVolume(store->audio->place_tower_sound
    , store->settings->volume[1]);
}

void destroy_game_sound(my_struct_t *store)
{
    sfSoundBuffer_destroy(store->audio->hurt_sound_buffer);
    sfSoundBuffer_destroy(store->audio->place_tower_sound_buffer);
    sfSound_destroy(store->audio->hurt_sound);
    sfSound_destroy(store->audio->place_tower_sound);
}