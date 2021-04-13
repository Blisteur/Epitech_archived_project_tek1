/*
** EPITECH PROJECT, 2020
** verif_map
** File description:
** file 2
*/

#include "include/navy.h"

int verif_nb(char nb, int lock)
{
    if (lock == 0) {
        if (nb > '8' || nb < '1')
            return (84);
    } else {
        if (nb > '5' || nb < '2')
            return (84);
    }
    return (0);
}

int verif_let(char lt)
{
    if (lt > 'H' || lt < 'A')
        return (84);
    return (0);
}

int verif_cord_test(int fd, char **map)
{
    verif_map_struct *verif_m = init_verif_map();
    char buff[8];

    for (int nb = 0; nb < 4; nb += 1) {
        read(fd, buff, 7);
        verif_cord_error(buff, verif_m);
        if (verif_m->error > 0 || (buff[2] != buff[5] && buff[3] != buff[6])) {
            destroy_verif_map(verif_m);
            return (84);
        }
        if (set_cord_map(buff, verif_m, map) == 84) {
            destroy_verif_map(verif_m);
            return (84);
        }
        read(fd, buff, 1);
    }
    destroy_verif_map(verif_m);
    return (0);
}

int verif_cord(int fd, my_struct *store)
{
    char **map = malloc(sizeof(char *) * 9);
    int error = 0;

    map[8] = '\0';
    for (int nb = 0; nb < 8; nb += 1) {
        map[nb] = malloc(sizeof(char) * 9);
        map[nb][8] = '\0';
    }
    for (int x = 0; x < 8; x += 1) {
        for (int y = 0; y < 8; y += 1) {
            map[x][y] = '.';
        }
    }
    error = verif_cord_test(fd, map);
    if (error == 0)
        make_ally_map(store, map);
    for (int nb = 0; nb < 8; nb += 1)
        free(map[nb]);
    free(map);
    return (error);
}