/*
** EPITECH PROJECT, 2021
** game
** File description:
** file 1
*/

#include "my_defender.h"

void game(void)
{
    my_struct_t *store = malloc(sizeof(my_struct_t));
    store->settings = malloc(sizeof(settings_t));
    store->score = malloc(sizeof(score_t));

    init_game(store);
    while (sfRenderWindow_isOpen(store->win)) {
        display_menu(store);
        analyse_events(store);
        sfRenderWindow_display(store->win);
    }
    destroy_game(store);
}