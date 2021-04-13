/*
** EPITECH PROJECT, 2020
** map
** File description:
** file 1
*/

#include "include/navy.h"

void make_ally_map(my_struct *store, char **map)
{
    for (int y = 2, tmp_y = 0; y < 10; y += 1, tmp_y += 1) {
        for (int x = 2, tmp_x = 0; x < 17; x += 2, tmp_x += 1) {
            store->ally_map[x][y] = map[tmp_x][tmp_y];
        }
    }
}

void init_map(char **tab)
{
    int fd = 0;
    char buff[2];

    fd = open("src/map.txt", O_RDONLY);
    if (fd == -1)
        return;
    for (int y = 0; y < 10; y += 1) {
        for (int x = 0; x < 17; x += 1) {
            read(fd, buff, 1);
            tab[x][y] = buff[0];
        }
        read(fd, buff, 1);
    }
    close(fd);
}

void creat_map(my_struct *store)
{
    store->ally_map = malloc(sizeof(char *) * 18);
    store->ally_map[17] = '\0';
    for (int nb = 0; nb < 17; nb += 1) {
        store->ally_map[nb] = malloc(sizeof(char) * 11);
        store->ally_map[nb][10] = '\0';
    }
    init_map(store->ally_map);
    store->enemy_map = malloc(sizeof(char *) * 18);
    store->enemy_map[17] = '\0';
    for (int nb = 0; nb < 17; nb += 1) {
        store->enemy_map[nb] = malloc(sizeof(char) * 11);
        store->enemy_map[nb][10] = '\0';
    }
    init_map(store->enemy_map);
}