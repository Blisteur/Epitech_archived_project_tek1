/*
** EPITECH PROJECT, 2020
** error
** File description:
** management
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/bsq.h"

int verif_nbr_line(char *buff, int nb_line, int nb_to_re)
{
    int count_line = 0;
    int tmp = 0;

    for (int count = 0; buff[count] != '\0';count += 1) {
        if (buff[count] != '.' && buff[count] != 'o' && buff[count] != '\n')
            return (1);
        if (buff[count] == '\n') {
            count_line += 1;
            if (tmp == 0) {
                tmp = count;
                nb_to_re = count + 1;
            }
            if (tmp != count)
                return (1);
            tmp += nb_to_re;
        }
    }
    if (count_line != nb_line)
        return (1);
    return (0);
}

int verif_first_line(char *buff, int *nb_line)
{

    for (int count = 0; buff[count] != '\n';count += 1) {
        if (buff[count] > '9' || buff[count] < '0')
            return (1);
        if (*nb_line != 0)
            *nb_line *= 10;
        *nb_line += (buff[count] - '0');
    }
    return (0);
}

int verif_line(int fd, char *buff, long int max, my_struct *store)
{
    int nb_line = 0;
    int nb_to_re = 0;

    read(fd, buff, max);
    if (verif_first_line(buff, &nb_line) == 1) {
        my_putstr_error("ERROR : first line must be a number of line !\n");
        return (1);
    }
    my_strcpy_after_n(buff, buff, my_nbrlen(nb_line, 10) + 1);
    store->buff_size = my_strlen(buff);
    if (verif_nbr_line(buff, nb_line, nb_to_re) == 1) {
        my_putstr_error("ERROR : incorrect syntax or number of line !\n");
        return (1);
    }
    store->nb_line = nb_line;
    return (0);
}

int error_management(int argc, char **argv, my_struct *store, struct stat info)
{
    int fd = 0;

    if (argc > 2 || argc < 2) {
        my_putstr_error("ERROR : to few or to many argument !\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        my_putstr_error("ERROR : file not find !\n");
        return (1);
    }
    stat(argv[1], &info);
    store->buff = malloc(info.st_size + 1);
    store->buff[info.st_size] = '\0';
    if (verif_line(fd, store->buff, info.st_size, store) == 1) {
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}