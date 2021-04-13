/*
** EPITECH PROJECT, 2020
** game
** File description:
** file 1
*/

#include "../include/game.h"

void analyse_events(my_game *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed
        || store->evt.key.code == sfKeyBackspace)
            sfRenderWindow_close(store->win);
        if (store->evt.type == sfEvtMouseButtonPressed
        && store->evt.mouseButton.button == 0
        && store->mode == MODE_MENU)
            menu_boutton_touch(store);
        if (store->evt.key.code == sfKeySpace && store->mode == MODE_MENU)
            store->mode = MODE_GAME;
        if (store->evt.key.code == sfKeySpace && store->mode == MODE_GAME)
            jump_player(store);
        game_over_event(store);
        pause_event(store);
    }
    events_per_mode(store);
}

void game(char *map_link)
{
    my_game *store = malloc(sizeof(my_game));

    init_game(store, map_link);
    while (sfRenderWindow_isOpen(store->win)) {
        drawsprite(store);
        timer(store);
        analyse_events(store);
        sfRenderWindow_display(store->win);
    }
    destroy_game(store);
}