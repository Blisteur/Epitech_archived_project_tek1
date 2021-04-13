/*
** EPITECH PROJECT, 2021
** get_score
** File description:
** file 1
*/

#include "my_defender.h"

void get_high_score(my_struct_t *store)
{
    int fd = open("src/files/score.txt", O_RDONLY);
    char buff[11];
    int nb_read = 0;

    buff[10] = '\0';
    if (fd == -1)
        return;
    nb_read = read(fd, buff, 10);
    if (nb_read == -1 || nb_read != 10) {
        close(fd);
        return;
    }
    for (int nb = 0; nb < 10; nb += 1) {
        if (buff[nb] <= '9' && buff[nb] >= '0')
            store->score->char_hi_score[nb + 12] = buff[nb];
        else
            store->score->char_hi_score[nb + 12] = '0';
    }
    close(fd);
}