/*
** EPITECH PROJECT, 2021
** music
** File description:
** file 1
*/

#include "../include/game.h"

void init_music(my_game *store)
{
    store->sound = malloc(sizeof(sound_t));
    store->sound->music = sfMusic_createFromFile("src/file/music.wav");
    store->sound->jump = sfMusic_createFromFile("src/file/jump.wav");
    store->sound->dead = sfMusic_createFromFile("src/file/dead.wav");
    store->sound->score = sfMusic_createFromFile("src/file/score.wav");
    sfMusic_setLoop(store->sound->music, sfTrue);
    sfMusic_setVolume(store->sound->music, 15);
}

void destroy_music(my_game *store)
{
    sfMusic_destroy(store->sound->music);
    sfMusic_destroy(store->sound->jump);
    sfMusic_destroy(store->sound->dead);
    sfMusic_destroy(store->sound->score);
    free(store->sound);
}

void score_music(my_game *store)
{
    sfTime tmp = {0};

    if (store->score->nb_co_score % 100 == 0
    && store->score->nb_co_score >= 100) {
        sfMusic_play(store->sound->score);
        sfMusic_setPlayingOffset(store->sound->score, tmp);
    }
}