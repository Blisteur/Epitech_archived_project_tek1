/*
** EPITECH PROJECT, 2021
** error_handler
** File description:
** file 1
*/

#include "my_sokoban.h"

void help(my_struct *store)
{
    int fd = open("src/help.txt", O_RDONLY);
    char buff[192];

    buff[192] = '\0';
    if (fd < 0) {
        my_putstr_error("ERROR: help file is mising !\n");
        destroy_struct(store, 1);
    }
    if (read(fd, buff, 192) == -1) {
        my_putstr_error("ERROR: help file is mising !\n");
        destroy_struct(store, 1);
    }
    my_printf("%s\n", buff);
    close(fd);
    destroy_struct(store, 1);
}

void verif_map(my_struct *store, const char *map_link)
{
    int fd = open(map_link, O_RDONLY);
    struct stat stat_p;

    if (fd < 0) {
        my_putstr_error("ERROR: map file is mising !\n");
        destroy_struct(store, 84);
    }
    if (stat(map_link, &stat_p) == -1) {
        my_putstr_error("ERROR: map file stat error !\n");
        close(fd);
        destroy_struct(store, 84);
    }
    init_map(store, fd, stat_p);
    if (create_map(store, map_link) == 84)
        destroy_struct(store, 84);
    close(fd);
}

void error_handler(my_struct *store, const int argc, const char * const *argv)
{
    if (argc < 2 || argc > 2) {
        my_putstr_error("ERROR: too few or too many argument !\n");
        destroy_struct(store, 84);
    }
    if (my_strcmp("-h", argv[1]) == 0)
        help(store);
    verif_map(store, argv[1]);
}