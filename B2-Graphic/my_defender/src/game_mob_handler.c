/*
** EPITECH PROJECT, 2021
** mob handler
** File description:
** file 1
*/

#include "my_defender.h"

void debug_print_mob(my_struct_t *store)
{
    game_mob_link_t *tmp;

    tmp = store->game->first_mob;
    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        my_printf("mob: %d : life: %d : %p :", tmp->type, tmp->life, tmp);
        my_printf("  %p", tmp->previous);
        my_printf("  %p\n", tmp->next);
        tmp = tmp->next;
    }
    my_printf("nb mob:%d\n", store->game->nb_mob);
}

void verif_mob_speed(my_struct_t *store)
{
    game_mob_link_t *tmp;

    tmp = store->game->first_mob;
    for (int nb = 0; nb < store->game->nb_mob; nb += 1) {
        if (tmp->cd < store->game->towers->elapsed && tmp->speed != 1
        && tmp->type != MISSILE)
            tmp->speed = 1;
        tmp = tmp->next;
    }
}

game_mob_link_t *add_mob_link(my_struct_t *store, game_mob_link_t *p
                            , void *type_mob, sfVector2f pos)
{
    game_mob_link_t *list = malloc(sizeof(game_mob_link_t));
    void(*ptr)(game_mob_link_t *, sfVector2f);

    ptr = type_mob;
    ptr(list, pos);
    list->next = p;
    if (p != NULL)
        p->previous = list;
    list->previous = NULL;
    p = list;
    store->game->nb_mob += 1;
    return (list);
}

void remove_mob_link(my_struct_t *store, game_mob_link_t *p)
{
    if (p == store->game->first_mob)
        store->game->first_mob = p->next;
    if (p->next != NULL)
        p->next->previous = p->previous;
    if (p->previous != NULL)
        p->previous->next = p->next;
    store->game->nb_mob -= 1;
    sfSprite_destroy(p->sprite);
    sfTexture_destroy(p->texture);
    free(p);
}

void remove_all_mob(my_struct_t *store)
{
    while (store->game->nb_mob != 0)
        remove_mob_link(store, store->game->first_mob);
}