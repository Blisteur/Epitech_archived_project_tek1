/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-mydefender-hildebert.jeanjean
** File description:
** tower_list_func2.c
*/

#include "my_defender.h"

void stun_units(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 180;
    struct game_mob_link_s *temp = store->game->first_mob;

    while (temp != NULL) {
        if (in_range(list->pos, radius, temp->pos) == 1 && temp->speed > 0
        && temp->type != MISSILE) {
            temp->speed = 0;
            temp->cd = towers->elapsed + (1000 * (list->power + 1));
        }
        temp = temp->next;
    }
    list->cd = towers->elapsed + 10000;
}

void slow_units(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 230;
    struct game_mob_link_s *temp = store->game->first_mob;

    while (temp != NULL) {
        if (in_range(list->pos, radius, temp->pos) == 1 && temp->speed >= 0.9
        && temp->type != MISSILE) {
            temp->speed = 0.7 - (list->power * 0.3);
            temp->cd = towers->elapsed + 300;
        }
        temp = temp->next;
    }
    list->cd = towers->elapsed + 200;
}

static void nuke_explode(my_struct_t *store, sfVector2f nuke)
{
    int radius = 146;
    struct game_mob_link_s *temp = store->game->first_mob;
    struct game_mob_link_s *temp2 = NULL;

    while (temp != NULL) {
        if (in_range(nuke, radius, temp->pos) == 1) {
            temp->life = temp->life - 500;
            temp2 = temp;
            temp = temp->next;
            verif_life_mob(store, temp2);
        }
        else
            temp = temp->next;
    }
}

void nuke_launcher(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 250 * ((list->power + 1) * 3);
    struct game_mob_link_s *temp = store->game->first_mob;

    while (temp != NULL) {
        if (in_range(list->pos, radius, temp->pos) == 1 && temp->life > 0) {
            nuke_explode(store, temp->pos);
            list->cd = towers->elapsed + 20000;
            break;
        }
        temp = temp->next;
    }
}