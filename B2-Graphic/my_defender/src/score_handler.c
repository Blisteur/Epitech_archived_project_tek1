/*
** EPITECH PROJECT, 2021
** score_handler
** File description:
** file 1
*/

#include "my_defender.h"

void update_hi_score(my_struct_t *store)
{
    const char *tmp_get = sfText_getString(store->score->hi_text);
    char tmp_set[24];
    int nb_hi_score = my_getnbr(tmp_get + 12);

    if (nb_hi_score > store->score->nb_cu_score)
        return;
    tmp_set[23] = '\0';
    my_strcpy(tmp_set, "high score: 0000000000");
    tmp_set[21] = ((store->score->nb_cu_score % 10) + '0');
    tmp_set[20] = (((store->score->nb_cu_score / 10 ) % 10) + '0');
    tmp_set[19] = (((store->score->nb_cu_score / 100 ) % 10) + '0');
    tmp_set[18] = (((store->score->nb_cu_score / 1000 ) % 10) + '0');
    tmp_set[17] = (((store->score->nb_cu_score / 10000 ) % 10) + '0');
    tmp_set[16] = (((store->score->nb_cu_score / 100000 ) % 10) + '0');
    tmp_set[15] = (((store->score->nb_cu_score / 1000000 ) % 10) + '0');
    tmp_set[14] = (((store->score->nb_cu_score / 10000000 ) % 10) + '0');
    tmp_set[13] = (((store->score->nb_cu_score / 100000000 ) % 10) + '0');
    tmp_set[12] = (((store->score->nb_cu_score / 1000000000 ) % 10) + '0');
    tmp_set[11] = (((store->score->nb_cu_score / 10000000000 ) % 10) + '0');
    sfText_setString(store->score->hi_text, tmp_set);
}