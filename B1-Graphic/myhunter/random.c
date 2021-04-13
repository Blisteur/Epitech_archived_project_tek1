/*
** EPITECH PROJECT, 2020
** random
** File description:
** file 1
*/

#include "include/game.h"

sfVector2f random_pose(int nb)
{
    sfVector2f res;

    srand(time(NULL));
    res.y = rand() % (800-400) + 400;
    if (nb == 1)
        res.x = -20;
    if (nb == 2)
        res.x = 1940;
    return (res);
}