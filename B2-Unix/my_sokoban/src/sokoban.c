/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** file 1
*/

#include "my_sokoban.h"

void print_map(my_struct *store)
{
    my_obj *tmp = store->first_obj;

    if (store->nb_line_map > LINES || store->nb_columns_map > COLS) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "Too small terminal !");
        refresh();
        return;
    }
    for (int nb = 0; nb < store->nb_line_map; nb += 1) {
        mvprintw(nb, 0, store->ddmap[nb]);
    }
    for (int nb = 0; nb < store->nbr_obj; nb += 1) {
        mvprintw(tmp->y, tmp->x, "%c", tmp->c);
        tmp = tmp->next;
    }
}

int sokoban(my_struct *store)
{
    int wincode = 0;

    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    while (store->loop_stop == 0) {
        print_map(store);
        refresh();
        move_player(store);
        wincode = is_win(store);
    }
    endwin();
    return (wincode);
}