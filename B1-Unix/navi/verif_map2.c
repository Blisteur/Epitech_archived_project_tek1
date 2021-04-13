/*
** EPITECH PROJECT, 2020
** verif_map
** File description:
** file 3
*/

#include "include/navy.h"

int verif_boat(char nb, verif_map_struct *verif_m)
{
    if (nb == '2')
        verif_m->boat2 -= 1;
    if (nb == '3')
        verif_m->boat3 -= 1;
    if (nb == '4')
        verif_m->boat4 -= 1;
    if (nb == '5')
        verif_m->boat5 -= 1;
    if (verif_m->boat2 < 0 || verif_m->boat3 < 0
        || verif_m->boat4 < 0 || verif_m->boat5 < 0)
        return (1);
    return (0);
}

int convert_let(char let)
{
    if (let == 'A')
        return (0);
    if (let == 'B')
        return (1);
    if (let == 'C')
        return (2);
    if (let == 'D')
        return (3);
    if (let == 'E')
        return (4);
    if (let == 'F')
        return (5);
    if (let == 'G')
        return (6);
    return (7);
}

void verif_cord_error(char *buff, verif_map_struct *verif_m)
{
    verif_m->error += verif_nb(buff[0], 1);
    verif_m->error += verif_boat(buff[0], verif_m);
    verif_m->error += verif_nb(buff[3], 0);
    verif_m->error += verif_nb(buff[6], 0);
    verif_m->error += verif_let(buff[2]);
    verif_m->error += verif_let(buff[5]);
}

int make_boat(char **map, verif_map_struct *verif_m, char boat, int nb)
{
    if (nb == 0)
        for (int x = verif_m->x_min; x <= verif_m->x_max; x += 1) {
            if (map[x][verif_m->y_max] != '.')
                return (84);
            map[x][verif_m->y_max] = boat;
        }
    else
        for (int y = verif_m->y_min; y <= verif_m->y_max; y += 1) {
            if (map[verif_m->x_max][y] != '.')
                return (84);
            map[verif_m->x_max][y] = boat;
        }
    return (0);
}

int set_cord_map(char *buff, verif_map_struct *verif_m, char **map)
{
    if (buff[2] != buff[5]) {
        verif_m->x_min = convert_let(buff[2]);
        verif_m->x_max = convert_let(buff[5]);
        verif_m->y_min = buff[3] - '0' - 1;
        verif_m->y_max = buff[3] - '0' - 1;
        if ((verif_m->x_max - verif_m->x_min) != (buff[0] - '0' - 1)
            || make_boat(map, verif_m, buff[0], 0) == 84)
            return (84);
    } else {
        verif_m->x_min = convert_let(buff[2]);
        verif_m->x_max = convert_let(buff[2]);
        verif_m->y_min = buff[3] - '0' - 1;
        verif_m->y_max = buff[6] - '0' - 1;
        if ((verif_m->y_max - verif_m->y_min) != (buff[0] - '0' - 1)
            || make_boat(map, verif_m, buff[0], 1) == 84)
            return (84);
    }
    return (0);
}