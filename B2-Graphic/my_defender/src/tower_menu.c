/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tower_menu.c
*/

#include "my_defender.h"

void tower_selector_text(my_struct_t *store, select_t *select)
{
    for (int a = 0; a != 8; a++) {
        if (store->game->nb_money >= select->prices[a])
            sfText_setColor(select->price[a], sfYellow);
        else
            sfText_setColor(select->price[a], sfWhite);
    }
}

void tower_selector(my_struct_t *store, select_t *select)
{
    if (select->selected == 0)
        click_selector(store, store->game->select);
    else if (store->game->select->selected < 0)
        selector_pos(store, store->game->select);
}

void tower_list_display(my_struct_t *store, list_t **list)
{
    struct list_s *temp = *list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(store->win, temp->sprite, NULL);
        temp = temp->next;
    }
}

void show_selector(my_struct_t *store, select_t *select)
{
    tower_list_display(store, &store->game->towers->list);
    for (int a = 0; a != 8; a++)
        sfRenderWindow_drawText(store->win, select->price[a], NULL);
    sfRenderWindow_drawSprite(store->win, select->sprite, NULL);
    if (select->can_place != 1)
        sfRenderWindow_drawRectangleShape(store->win, select->stop, NULL);
}