/*
** EPITECH PROJECT, 2020
** tower
** File description:
** tower_menu.c
*/
#include "my_defender.h"

sfIntRect set_intrect(int left, int top, int width, int height)
{
    sfIntRect temp;

    temp.left = left;
    temp.top = top;
    temp.width = width;
    temp.height = height;
    return (temp);
}

struct select_s *apply_prices(int prices[8], select_t *select)
{
    for (int a = 0; a != 8; a++)
        select->prices[a] = prices[a];
    select->buy[0] = set_intrect(1440, 4, 96, 184);
    select->buy[1] = set_intrect(1536, 4, 96, 184);
    select->buy[2] = set_intrect(1440, 188, 96, 184);
    select->buy[3] = set_intrect(1536, 188, 96, 184);
    select->buy[4] = set_intrect(1440, 372, 96, 184);
    select->buy[5] = set_intrect(1536, 372, 96, 184);
    select->buy[6] = set_intrect(1440, 560, 192, 128);
    select->buy[7] = set_intrect(1440, 692, 192, 168);
    return (select);
}

struct select_s *load_select_texts(struct select_s *select, my_struct_t *store)
{
    int units1[3] = {20, 1470, 163};
    int units2[3] = {20, 1566, 163};
    int units3[3] = {20, 1470, 343};
    int units4[3] = {20, 1566, 343};
    int units5[3] = {20, 1470, 531};
    int units6[3] = {20, 1566, 531};
    int units7[3] = {20, 1517, 663};
    int units8[3] = {20, 1517, 835};

    select->price[0] = init_text(store->buttonfont, "100", units1, sfWhite);
    select->price[1] = init_text(store->buttonfont, "800", units2, sfWhite);
    select->price[2] = init_text(store->buttonfont, "200", units3, sfWhite);
    select->price[3] = init_text(store->buttonfont, "1200", units4, sfWhite);
    select->price[4] = init_text(store->buttonfont, "400", units5, sfWhite);
    select->price[5] = init_text(store->buttonfont, "2400", units6, sfWhite);
    select->price[6] = init_text(store->buttonfont, "800", units7, sfWhite);
    select->price[7] = init_text(store->buttonfont, "9600", units8, sfWhite);
    return (select);
}

struct select_s *load_selector(my_struct_t *store)
{
    struct select_s *select = malloc(sizeof(select_t));
    int temp[8] = {100, 800, 200, 1200, 400, 2400, 800, 9600};
    sfVector2f zoom = {4, 4};
    sfVector2f origin = {8, 16};

    select->small = sfTexture_createFromFile("sprites/towers_16_32.png", NULL);
    select->big = sfTexture_createFromFile("sprites/generator_32.png", NULL);
    select->sprite = sfSprite_create();
    select->pos.left = -400;
    select->pos.top = -400;
    select->pos.width = 64;
    select->pos.height = 128;
    select->selected = 0;
    select = apply_prices(temp, select);
    select = load_select_texts(select, store);
    sfSprite_setScale(select->sprite, zoom);
    sfSprite_setOrigin(select->sprite, origin);
    select->stop = load_stop();
    select->can_place = 1;
    return (select);
}

void free_selector(select_t *select)
{
    for (int a = 0; a != 8; a++)
        sfText_destroy(select->price[a]);
    sfTexture_destroy(select->big);
    sfTexture_destroy(select->small);
    sfSprite_destroy(select->sprite);
    sfRectangleShape_destroy(select->stop);
    free(select);
}