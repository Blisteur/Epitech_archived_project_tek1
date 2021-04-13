/*
** EPITECH PROJECT, 2021
** antman.c
** File description:
** file 1
*/

#include "../include/antman.h"

int verif_c_p(char *buff)
{
    char tmp = '\t';
    int n = 0;

    tmp = tmp << 7;
    for (n = 0; buff[n]; n += 1) {
        if ((buff[n] & tmp) >> 7 != '\0') {
            return (n);
        }
    }
    return (n);
}

void modif_bit(unsigned int lop, unsigned char res,
                unsigned char tmp, char *buff)
{
    int tmp_nb = 6;
    int buff_nb = 1;

    for (int i = 0; i < 7; i += 1) {
        buff[lop + i] = buff[lop + i] << buff_nb;
        tmp = buff[lop + i + 1];
        tmp = tmp >> tmp_nb;
        res = buff[lop + i] | tmp;
        buff_nb += 1;
        tmp_nb -= 1;
        my_putchar(res);
    }
}

int read_buff(int fd, unsigned int nb)
{
    char buff[nb + 1];
    unsigned char tmp = 0;
    unsigned char res = 0;
    unsigned int lop = 0;

    buff[nb] = '\0';
    if (read(fd, buff, nb) == -1)
        return (84);
    nb = verif_c_p(buff);
    for (lop = 0; lop + 8 <= nb; lop += 8) {
        modif_bit(lop, res, tmp, buff);
    }
    if (buff[lop] != '\0') {
        my_putchar('1');
        my_putstr(buff + lop);
    }
    return (0);
}

int antman(char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat stat_p;

    if (stat(argv[1], &stat_p) == -1)
        return (84);
    return (read_buff(fd, stat_p.st_size));
}