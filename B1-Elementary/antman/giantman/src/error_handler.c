/*
** EPITECH PROJECT, 2021
** error_handler
** File description:
** file 1
*/

#include "../include/giantman.h"

int verif_path(char *path, int nb)
{
    int fd = open(path, O_RDONLY);
    struct stat stat_p;

    if (fd < 0)
        return (84);
    close(fd);
    if (stat(path, &stat_p) == -1)
        return (84);
    if (S_ISREG(stat_p.st_mode) != 1)
        return (84);
    if (nb < 1 || nb > 3)
        return (84);
    return (0);
}

int error_handler(int argc, char **argv)
{
    int error = 0;

    if (argc != 3)
        return (84);
    error += verif_path(argv[1], my_getnbr(argv[2]));
    if (error > 0)
        my_putstr_error("ERROR: incorect file or missing file !\n");
    return (error);
}