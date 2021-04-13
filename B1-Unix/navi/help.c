/*
** EPITECH PROJECT, 2020
** help
** File description:
** file 1
*/

#include "include/navy.h"

int help(void)
{
    int fd = 0;
    char buff[205];

    fd = open("src/help.txt", O_RDONLY);
    if (fd == -1) {
        my_putstr_error("ERROR: missing help file !\n");
        return (84);
    }
    read(fd, buff, 204);
    my_printf("%s\n", buff);
    close(fd);
    return (0);
}