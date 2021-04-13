/*
** EPITECH PROJECT, 2020
** print_map
** File description:
** file 1
*/

#include "include/navy.h"

void print_map(my_struct *store)
{
    write(1, "\nmy positions:\n", 15);
    for (int y = 0; y < 10; y += 1) {
        for (int x = 0; x < 17; x += 1) {
            my_putchar(store->ally_map[x][y]);
        }
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 20);
    for (int y = 0; y < 10; y += 1) {
        for (int x = 0; x < 17; x += 1) {
            my_putchar(store->enemy_map[x][y]);
        }
        write(1, "\n", 1);
    }
}