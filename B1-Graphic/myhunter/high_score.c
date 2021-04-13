/*
** EPITECH PROJECT, 2020
** verif_high_score
** File description:
** file 1
*/

#include "include/game.h"

int my_put_nbr_in_file(int nb, int fd)
{
    if (nb < 10) {
        nb += '0';
        write(fd, &nb, 1);
    } else if (nb > 9){
        my_put_nbr_in_file(nb / 10, fd);
        my_put_nbr_in_file(nb % 10, fd);
    }
    return (0);
}

unsigned int verif_high_score(void)
{
    int fd;
    char buff[9];

    buff[8] = '\0';
    fd = open("src/score.txt", O_RDWR);
    if (fd < 0) {
        my_putstr_error("ERROR: score file is missing !\n");
        my_putstr_error("Creat new score file !\n");
        return (0);
    }
    read(fd, buff, 8);
    close(fd);
    return (my_getnbr(buff));
}

void new_score(my_game *store)
{
    int fd;
    unsigned int nb = store->score->score;

    fd = open("src/score.txt", O_WRONLY);
    if (fd < 0) {
        open("src/score.txt", O_CREAT);
        fd = open("src/score.txt", O_WRONLY);
    }
    my_put_nbr_in_file(nb, fd);
    my_printf("Well played your new high score is %d\n", store->score->score);
    close(fd);
}