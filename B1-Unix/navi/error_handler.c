/*
** EPITECH PROJECT, 2020
** error_handler
** File description:
** file 1
*/

#include "include/navy.h"

int verif_map(char *path_file, my_struct *store)
{
    int fd = 0;

    fd = open(path_file, O_RDONLY);
    if (fd == -1) {
        my_putstr_error("ERROR: invalide map !\n");
        return (84);
    }
    if (verif_cord(fd, store) == 84) {
        my_putstr_error("ERROR: invalide map !\n");
        close(fd);
        return (84);
    }
    close(fd);
    fd = open("src/map.txt", O_RDONLY);
    if (fd == -1) {
        my_putstr_error("ERROR: missing map file !\n");
        return (84);
    }
    close(fd);
    return (0);
}

int is_number(char *str)
{
    for (int nb = 0; str[nb] != '\0'; nb += 1) {
        if (str[nb] > '9' || str[nb] < '0') {
            my_putstr_error("ERROR: invalide PID !\n");
            return (84);
        }
    }
    return (0);
}

int error_handler(int argc, char **argv, my_struct *store)
{
    int error = 0;

    if (argc == 1 || argc > 3) {
        my_putstr_error("ERROR: too few or too many arguments !\n");
        my_putstr_error("USE: \"./navy -h\" for more information !\n");
        return (84);
    }
    if (argc == 2) {
        error += verif_map(argv[1], store);
    }
    if (argc == 3) {
        error += verif_map(argv[2], store);
        error += is_number(argv[1]);
    }
    if (error > 0) {
        my_putstr_error("USE: \"./navy -h\" for more information !\n");
        return (84);
    }
    return (0);
}