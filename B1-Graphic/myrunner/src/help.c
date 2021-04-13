/*
** EPITECH PROJECT, 2020
** help
** File description:
** file 1
*/

#include "../include/game.h"

int help(void)
{
    int fd = open("src/file/help.txt", O_RDONLY);
    char buff[HELP_MSG_SIZE + 1];

    if (fd == -1) {
        my_putstr_error("ERROR: missing help file !\n");
        return (84);
    }
    read(fd, buff, HELP_MSG_SIZE);
    my_printf("%s\n", buff);
    close(fd);
    return (0);
}