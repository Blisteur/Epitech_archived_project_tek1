/*
** EPITECH PROJECT, 2021
** antman.c
** File description:
** file 1
*/

#include "../include/giantman.h"

void modif_bit(char *buff, unsigned int lop, int tmp_nb, int buff_nb)
{
    unsigned char tmp = 0;

    tmp = buff[lop];
    tmp = tmp >> 1;
    my_putchar(tmp);
    for (int i = 0; i < 6; i += 1) {
        buff[lop + i] = buff[lop + i] << buff_nb;
        tmp = buff[lop + i + 1];
        tmp = tmp >> tmp_nb;
        tmp = buff[lop + i] | tmp;
        tmp = tmp << 1;
        tmp = tmp >> 1;
        my_putchar(tmp);
        buff_nb -= 1;
        tmp_nb += 1;
    }
        tmp = buff[lop + 6];
        tmp = tmp << 1;
        tmp = tmp >> 1;
        my_putchar(tmp);
}

int read_buff(int fd, unsigned int nb)
{
    char buff[nb + 1];
    unsigned int lop = 0;

    buff[nb] = '\0';
    if (read(fd, buff, nb) == -1)
        return (84);
    for (lop = 0; lop + 7 <= nb; lop += 7) {
        if (buff[lop] == '1')
        break;
        modif_bit(buff, lop, 2, 6);
    }
    if (buff[lop] != '\0')
        my_putstr(buff + lop + 1);
    return (0);
}

int giantman(char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat stat_p;

    if (stat(argv[1], &stat_p) == -1)
        return (84);
    return (read_buff(fd, stat_p.st_size));
}