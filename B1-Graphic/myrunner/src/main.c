/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** file 1
*/

#include "../include/game.h"

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        if (help() == 0)
            return (0);
        return (84);
    }
    if (error_hendler(argc, argv) == 84)
        return (84);
    game(argv[1]);
    return (0);
}