/*
** EPITECH PROJECT, 2020
** error_handler
** File description:
** file 1
*/

#include "../include/game.h"

int verif_map_c(int fd)
{
    char buff[2];

    buff[0] = '0';
    buff[1] = '\0';
    while (buff[0] != '2') {
        read(fd, buff, 1);
        if (buff[0] < '0' || buff[0] > '2')
            return (84);
    }
    return (0);
}

int verif_map(char *link)
{
    int fd = open(link, O_RDONLY);

    if (link[0] == '-' && link[1] == 'i' && link[2] == '\0')
        return (0);
    if (fd == -1) {
        my_putstr_error("ERROR: missing map !\n");
        return (84);
    }
    if (verif_map_c(fd) == 84) {
        my_putstr_error("ERROR: unrecognized map !\n");
        return (84);
    }
    close(fd);
    return (0);
}

int error_hendler(int argc, char **argv)
{
    int error = 0;
    if (argc < 2 || argc > 2) {
        my_putstr_error("ERROR: too few or too many arguments !\n");
        my_putstr_error("USE: \"./my_runner -h\" for more information !\n");
        return (84);
    }
    error += verif_file();
    error += verif_map(argv[1]);
    if (error == 84) {
        my_putstr_error("USE: \"./my_runner -h\" for more information !\n");
        return (84);
    }
    return (0);
}