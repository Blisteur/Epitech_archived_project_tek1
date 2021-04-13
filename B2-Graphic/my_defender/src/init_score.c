/*
** EPITECH PROJECT, 2021
** init_score
** File description:
** file 1
*/

#include "my_defender.h"

void init_score(my_struct_t *store)
{
    int tmp[3] = { 40, 0, 800 };

    store->score->char_hi_score = malloc(sizeof(char) * 23);
    store->score->char_hi_score[22] = '\0';
    my_strcpy(store->score->char_hi_score, "high score: 0000000000");
    get_high_score(store);
    store->score->nb_cu_score = 0;
    store->score->hi_text = init_text(store->fancyfont
                            , "high score: 0000000000", tmp, sfBlack);
    sfText_setString(store->score->hi_text, store->score->char_hi_score);
    free(store->score->char_hi_score);
}

void destroy_score(my_struct_t *store)
{
    sfText_destroy(store->score->hi_text);
    free(store->score);
}