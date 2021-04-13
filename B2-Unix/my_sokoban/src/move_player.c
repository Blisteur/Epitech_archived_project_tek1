/*
** EPITECH PROJECT, 2021
** move player
** File description:
** file 1
*/

#include "my_sokoban.h"

void move_player_down(my_struct *store)
{
    int next_y = (store->first_obj->y + 1);

    if (next_y < store->nb_line_map
    && store->ddmap[next_y][store->first_obj->x] != '#') {
        if (verif_case_move(store, store->first_obj->x, next_y, 'd') == 0)
            store->first_obj->y += 1;
    }
}

void move_player_up(my_struct *store)
{
    int next_y = (store->first_obj->y - 1);

    if (next_y > 0
    && store->ddmap[next_y][store->first_obj->x] != '#') {
        if (verif_case_move(store, store->first_obj->x, next_y, 'u') == 0)
            store->first_obj->y -= 1;
    }
}

void move_player_left(my_struct *store)
{
    int next_x = (store->first_obj->x - 1);

    if (next_x > 0
    && store->ddmap[store->first_obj->y][next_x] != '#') {
        if (verif_case_move(store, next_x, store->first_obj->y, 'l') == 0)
            store->first_obj->x -= 1;
    }
}

void move_player_right(my_struct *store)
{
    int next_x = (store->first_obj->x + 1);

    if ((store->ddmap[store->first_obj->y][next_x] != '\0'
    || store->ddmap[store->first_obj->y][next_x] != '\n' )
    && store->ddmap[store->first_obj->y][next_x] != '#') {
        if (verif_case_move(store, next_x, store->first_obj->y, 'r') == 0)
            store->first_obj->x += 1;
    }
}

void move_player(my_struct *store)
{
    int cmd = getch();

    if (cmd == KEY_DOWN)
        move_player_down(store);
    if (cmd == KEY_UP)
        move_player_up(store);
    if (cmd == KEY_LEFT)
        move_player_left(store);
    if (cmd == KEY_RIGHT)
        move_player_right(store);
    if (cmd == ' ')
        reset(store);
    if (cmd == 'q')
        store->loop_stop += 1;
}