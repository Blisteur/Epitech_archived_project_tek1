/*
** EPITECH PROJECT, 2021
** game handler
** File description:
** file 2
*/

#include "my_defender.h"

void analyse_events_game(my_struct_t *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed)
            sfRenderWindow_close(store->win);
        if (store->evt.key.code == sfKeyQ
        && store->evt.type == sfEvtKeyReleased)
            store->game->stop = 1;
        tower_selector(store, store->game->select);
        pause_event(store);
    }
}

void display_game(struct my_struct_s *store)
{
    game_mob_link_t *tmp = store->game->first_mob;

    sfRenderWindow_drawSprite(store->win, store->game->backsp, NULL);
    sfRenderWindow_drawText(store->win, store->game->text_time, NULL);
    sfRenderWindow_drawText(store->win, store->game->text_life, NULL);
    sfRenderWindow_drawText(store->win, store->game->text_money, NULL);
    show_selector(store, store->game->select);
    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        sfRenderWindow_drawSprite(store->win, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    sfRenderWindow_drawSprite(store->win, store->game->m_tower_s, NULL);
    sfRenderWindow_display(store->win);
}

void game_loop(my_struct_t *store)
{
    while (store->game->stop == 0 && sfRenderWindow_isOpen(store->win)) {
        timer(store);
        if (store->game->mode == MODE_GAME)
            display_game(store);
        if (store->game->mode == MODE_PAUSE)
            display_pause(store->win, store->game->pause);
        analyse_events_game(store);
        tower_act(store, &store->game->towers->list, store->game->towers);
    }
}