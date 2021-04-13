/*
** EPITECH PROJECT, 2021
** win
** File description:
** file 1
*/

#include "../include/game.h"

void restart_win(my_game *store)
{
    sfVector2f tmp_pose = {850, 300};
    char *tmp_text = malloc(sizeof(char) * 17);

    tmp_text[16] = '\0';
    my_strcpy(tmp_text, "YOU  WIN !");
    sfText_setString(store->score->hi_text, tmp_text);
    sfText_setPosition(store->score->hi_text, tmp_pose);
    sfRenderWindow_drawText(store->win, store->score->hi_text, NULL);
    sfText_setString(store->score->hi_text, store->score->text);
    sfText_setPosition(store->score->hi_text, store->score->pose);
    free(tmp_text);
    store->mode = MODE_END;
}

void verif_win(my_game *store)
{
    mob_t *tmp = store->mob_list_first;
    int tmp_nb = 0;

    for (int nb = 0; nb < store->nb_link_mob; nb += 1) {
        if (tmp->pose.x < -400)
            tmp_nb += 1;
        tmp = tmp->next;
    }
    if (tmp_nb == store->nb_link_mob) {
        restart_win(store);
    }
}