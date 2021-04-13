/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-mydefender-hildebert.jeanjean
** File description:
** tower_list_func.c
*/

#include "my_defender.h"

void apply_snipe(my_struct_t *store, list_t *list, tower_t *towers, int tp[3])
{
    int high = tp[0];
    int best = tp[1];
    struct game_mob_link_s *temp = store->game->first_mob;

    if (high != 0) {
        for (int a = 0; a != best && temp != NULL; a++)
            temp = temp->next;
        temp->life = temp->life - (50 * ((list->power * 3) + 1));
        verif_life_mob(store, temp);
        list->cd = towers->elapsed + 6000;
    }
}

void snipe_healthiest(my_struct_t *store, list_t *list, tower_t *towers)
{
    struct game_mob_link_s *temp = store->game->first_mob;
    int high = 0;
    int best = 0;
    int tmp[3];

    for (int nb = 0; temp != NULL; nb++) {
        if (in_range(list->pos, 300, temp->pos) == 1) {
            if (temp->life > high) {
                high = temp->life;
                best = nb;
            }
        }
        temp = temp->next;
    }
    tmp[0] = high;
    tmp[1] = best;
    tmp[2] = 0;
    apply_snipe(store, list, towers, tmp);
}

void multi_attack(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 132 * (0.5 + (list->power + 1));
    struct game_mob_link_s *temp = store->game->first_mob;
    struct game_mob_link_s *temp2 = NULL;

    while (temp != NULL) {
        if (in_range(list->pos, radius, temp->pos) == 1 && temp->life > 0) {
            temp->life = temp->life - 5;
            temp2 = temp;
            temp = temp->next;
            verif_life_mob(store, temp2);
        }
        else
            temp = temp->next;
    }
    list->cd = towers->elapsed + 1000;
}

void single_attack(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 164;
    struct game_mob_link_s *temp = store->game->first_mob;

    while (temp != NULL) {
        if (in_range(list->pos, radius, temp->pos) == 1 && temp->life > 0) {
            temp->life = temp->life - 10;
            verif_life_mob(store, temp);
            break;
        }
        temp = temp->next;
    }
    list->cd = towers->elapsed + 500 / (list->power + 1);
}

void power_radius(my_struct_t *store, list_t *list, tower_t *towers)
{
    int radius = 150 * (list->power + 1);
    struct list_s *temp = store->game->towers->list;

    while (temp != NULL) {
        if (temp->power == 0 && temp->id != list->id) {
            if (in_range(list->pos, radius, temp->pos) == 1)
                temp->power = 1;
        }
        temp = temp->next;
    }
    list->cd = towers->elapsed + 1000;
}