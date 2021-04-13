/*
** EPITECH PROJECT, 2020
** destroy game
** File description:
** file 1
*/

#include "include/game.h"

void destroy_game(my_game *store)
{
    my_printf("Your score is : %d\n", store->score->score);
    if (store->score->score > store->score->high_score)
        new_score(store);
    else
        my_printf("The best score is : %d\n", store->score->high_score);
    sfRenderWindow_destroy(store->win);
    sfClock_destroy(store->timer->clock_anim);
    sfClock_destroy(store->timer->clock_move);
    destroy_life(store);
    destroy_texture(store);
    destroy_sprite(store);
    sfMusic_destroy(store->sound);
    free(store->rect);
    free(store->score);
    free(store->pose);
    free(store->texture);
    free(store->sprite);
    free(store->timer);
    free(store);
}