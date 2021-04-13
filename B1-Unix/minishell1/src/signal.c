/*
** EPITECH PROJECT, 2021
** signal
** File description:
** file 1
*/

#include "mysh.h"

void signal_handler(int code)
{
    if (code == 11)
        write(1, "\n$> ", 4);
}