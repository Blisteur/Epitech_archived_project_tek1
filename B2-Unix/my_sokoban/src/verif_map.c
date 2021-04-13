/*
** EPITECH PROJECT, 2021
** verif_map
** File description:
** file 1 : link error_handler
*/

#include "my_sokoban.h"

int verif_c(char *map)
{
    for (int nb = 0; map[nb]; nb += 1) {
        if (map[nb] != '#' && map[nb] != 'P'
            && map[nb] != 'X' && map[nb] != 'O'
            && map[nb] != ' ' && map[nb] != '\n') {
                my_putstr_error("ERROR: invalid map !\n");
                return (84);
            }
    }
    return (0);
}

int verif_nb_c(char *map)
{
    int nb_case = 0;
    int nb_pt = 0;
    int nb_pl = 0;

    for (int nb = 0; map[nb]; nb += 1) {
        if (map[nb] == 'P')
            nb_pl += 1;
        if (map[nb] == 'O')
            nb_case += 1;
        if (map[nb] == 'X')
            nb_pt += 1;
    }
    if (nb_pl > 1 || nb_pl < 1) {
        my_putstr_error("ERROR: invalid map !\n");
        return (84);
    } else if (nb_pt != nb_case || nb_case < 1) {
        my_putstr_error("ERROR: invalid map !\n");
        return (84);
    }
    return (0);
}

void init_map(my_struct *store, int fd, struct stat stat_p)
{
    store->map = malloc(sizeof(char) * (stat_p.st_size + 1));
    if (store->map == NULL) {
        my_putstr_error("ERROR: malloc NULL !\n");
        close(fd);
        destroy_struct(store, 84);
    }
    store->map[stat_p.st_size] = '\0';
    if (read(fd, store->map, stat_p.st_size) == -1) {
        my_putstr_error("ERROR: map file read error !\n");
        close(fd);
        destroy_struct(store, 84);
    }
    if (verif_c(store->map) == 84)
        destroy_struct(store, 84);
    if (verif_nb_c(store->map) == 84)
        destroy_struct(store, 84);
}