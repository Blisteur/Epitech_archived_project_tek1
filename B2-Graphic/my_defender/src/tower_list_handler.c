/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tower_list_handler.c
*/

#include "my_defender.h"

sfSprite *add_tower_sprite(tower_t *towers, select_t *select, list_t *list)
{
    sfSprite *tower = sfSprite_create();
    sfVector2f scale = {4, 4};
    sfIntRect crop = {0, 32, 16, 32};

    crop.left = 16 * ((select->selected * -1) - 1);
    sfSprite_setScale(tower, scale);
    if (select->selected == -8) {
        crop.left = 0;
        crop.width = 32;
        sfSprite_setTexture(tower, towers->big, sfFalse);
    }
    else
        sfSprite_setTexture(tower, select->small, sfFalse);
    sfSprite_setTextureRect(tower, crop);
    list->box = select->pos;
    list->pos.x = select->pos.left;
    list->pos.y = select->pos.top;
    sfSprite_setPosition(tower, list->pos);
    return (tower);
}

void add_tower(list_t **list, tower_t *tower, select_t *select, my_struct_t *s)
{
    struct list_s *temp = malloc(sizeof(list_t));
    static int id = 0;

    id = id + 1;
    audio_run_place_tower(s);
    temp->id = id;
    temp->sprite = add_tower_sprite(tower, select, temp);
    temp->type = select->selected * - 1 - 1;
    temp->power = 0;
    temp->cd = 0.0;
    tower_has_power(s, temp);
    temp->next = *list;
    (*list) = temp;
}

void free_tower_list(struct list_s **list)
{
    struct list_s *temp;
    struct list_s *cur = *list;

    if (*list != NULL) {
        while (cur != NULL) {
            temp = cur->next;
            sfSprite_destroy(cur->sprite);
            free(cur);
            cur = temp;
        }
        *list = NULL;
    }
}

void free_towers(tower_t *towers)
{
    sfTexture_destroy(towers->small);
    sfTexture_destroy(towers->big);
    free_tower_list(&towers->list);
    sfClock_destroy(towers->clock);
    free(towers);
}

struct tower_s *init_towers(void)
{
    struct tower_s *towers = malloc(sizeof(tower_t));

    towers->ptr[0] = single_attack;
    towers->ptr[1] = snipe_healthiest;
    towers->ptr[2] = multi_attack;
    towers->ptr[3] = nuke_launcher;
    towers->ptr[4] = slow_units;
    towers->ptr[5] = stun_units;
    towers->ptr[6] = power_radius;
    towers->ptr[7] = power_all;
    towers->big = sfTexture_createFromFile("./sprites/generator_32.png",
    NULL);
    towers->small = sfTexture_createFromFile("./sprites/towers_16_32.png",
    NULL);
    towers->clock = sfClock_create();
    towers->all = 0;
    towers->list = NULL;
    return (towers);
}