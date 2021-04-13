/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "../include/antman.h"

int main(int argc, char **argv)
{
    if (error_handler(argc, argv) > 0)
        return (84);
    return (antman(argv));
}