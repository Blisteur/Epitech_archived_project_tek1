/*
** EPITECH PROJECT, 2020
** struct_handler
** File description:
** file 1
*/

#include "../include/game.h"

void init_game(my_game *store, char *map_link)
{
    store->mode = MODE_MENU;
    store->nb_link_mob = 0;
    store->mob_list_first = NULL;
    store->mob_list_last = NULL;
    init_clock(store);
    init_score(store);
    init_music(store);
    init_game_over(store);
    get_settings(store);
    if (store->fullscreen == 0)
        store->win = sfRenderWindow_create(store->video_mode,
                                        N_GAME, sfResize | sfClose, NULL);
    else
        store->win = sfRenderWindow_create(store->video_mode,
                                        N_GAME, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(store->win, store->fps);
    store->menu = make_menu(store->menu);
    create_parallax(store);
    create_player(store);
    make_map(store, map_link);
}

void destroy_game(my_game *store)
{
    mob_t *tmp = store->mob_list_first;

    sfRenderWindow_destroy(store->win);
    make_high_score(store);
    destroy_menu(store);
    destroy_parallax(store);
    destroy_player(store);
    destroy_score(store);
    destroy_music(store);
    destroy_clock(store);
    destroy_game_over(store);
    while (store->nb_link_mob != 0) {
        remove_link_mob(store, tmp);
        tmp = store->mob_list_first;
    }
    free(store->map);
    free(store);
}

mob_t *add_link_mob(my_game *store, mob_t *p, enum mob_type nb)
{
    mob_t *list = malloc(sizeof(mob_t));

    list->mob = nb;
    list->next = p;
    if (p != NULL)
        p->previous = list;
    list->previous = NULL;
    p = list;
    if (store->nb_link_mob == 0)
        store->mob_list_last = list;
    store->nb_link_mob += 1;
    return (list);
}

void remove_link_mob(my_game *store, mob_t *p)
{
    if (p->previous == NULL)
        store->mob_list_first = p->next;
    else
        p->previous->next = p->next;
    if (p->next == NULL)
        store->mob_list_last = p->previous;
    else
        p->next->previous = p->previous;
    sfSprite_destroy(p->sprite);
    sfTexture_destroy(p->texture);
    store->nb_link_mob -= 1;
    free(p);
}