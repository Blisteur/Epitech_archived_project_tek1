/*
** EPITECH PROJECT, 2021
** random
** File description:
** file 1
*/

#include "../include/game.h"

int random_height_jump(void)
{
    int tmp = 0;

    srand(time(NULL));
    tmp = rand() % (300-250) + 250;
    return (tmp);
}

mob_type random_mob(int nb)
{
    int tmp = 0;

    srand(nb);
    tmp = rand() % (3-0) + 0;
    return (tmp);
}

int random_height_bird(int nb)
{
    int tmp = 0;

    srand(nb);
    tmp = rand() % (3-0) + 0;
    if (tmp == 0)
        return (550);
    if (tmp == 1)
        return (500);
    if (tmp == 2)
        return (400);
    return (550);
}

int random_mob_spawn(int nb)
{
    int tmp = 0;

    srand(nb);
    tmp = rand() % (2-1) + 1;
    return (tmp);
}