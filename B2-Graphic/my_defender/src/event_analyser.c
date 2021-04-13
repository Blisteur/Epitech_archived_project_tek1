/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** event_analyser.c
*/

#include "my_defender.h"

void analyse_events(my_struct_t *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed)
            sfRenderWindow_close(store->win);
        interact_with_button(store->menu->quit, store->evt, store);
        interact_with_button(store->menu->start, store->evt, store);
        interact_with_button(store->menu->settings, store->evt, store);
        interact_with_button(store->menu->manual, store->evt, store);
        if (store->menu->options->active == 1)
            interact_options(store);
    }
}