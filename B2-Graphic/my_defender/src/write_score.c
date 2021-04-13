/*
** EPITECH PROJECT, 2021
** write_score.c
** File description:
** file 1
*/

#include "my_defender.h"

void write_score(my_struct_t *store)
{
    int fd = open("src/files/score.txt", O_WRONLY | O_CREAT, 00666);
    const char *tmp_get = sfText_getString(store->score->hi_text);

    if (fd == -1)
        return;
    store->score->char_hi_score = my_strdup(tmp_get);
    my_putstr_to_file(store->score->char_hi_score + 12, fd);
    free(store->score->char_hi_score);
    close(fd);
}