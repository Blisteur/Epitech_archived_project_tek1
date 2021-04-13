/*
** EPITECH PROJECT, 2021
** update text
** File description:
** file 1
*/

#include "my_defender.h"

void update_time_txt(my_struct_t *store)
{
    const char *tmp_get = sfText_getString(store->game->text_time);
    char tmp_set[12];
    int second = my_getnbr(tmp_get + 9);
    int minute = my_getnbr(tmp_get + 6);

    second += 1;
    if (second == 30 || second == 60)
        game_spawn_mob(store, 0);
    if (second >= 60) {
        second = 0;
        minute += 1;
    }
    my_strcpy(tmp_set, "TIME:\n00:00");
    tmp_set[10] = ((second % 10) + '0');
    tmp_set[9] = ((second / 10) + '0');
    tmp_set[7] = ((minute % 10) + '0');
    tmp_set[6] = ((minute / 10) + '0');
    sfText_setString(store->game->text_time, tmp_set);
}

void update_life_txt(my_struct_t *store, int nb)
{
    const char *tmp_get = sfText_getString(store->game->text_life);
    char tmp_set[12];
    int life = my_getnbr(tmp_get + 6);

    life -= nb;
    my_strcpy(tmp_set, "LIFE:\n00000");
    tmp_set[10] = ((life % 10) + '0');
    tmp_set[9] = (((life / 10 ) % 10) + '0');
    tmp_set[8] = (((life / 100 ) % 10) + '0');
    tmp_set[7] = (((life / 1000 ) % 10) + '0');
    tmp_set[6] = (((life / 10000 ) % 10) + '0');
    sfText_setString(store->game->text_life, tmp_set);
    if (life <= 0)
        store->game->stop = 1;
}

void update_money_txt(my_struct_t *store, int nb, char c)
{
    char tmp_set[13];

    if (c == '+') {
        store->game->nb_money += nb;
        store->score->nb_cu_score += nb;
    }
    else if (c == '-')
        store->game->nb_money -= nb;
    if (store->game->nb_money > 99999)
        store->game->nb_money = 99999;
    if (store->game->nb_money < 0)
        store->game->nb_money = 0;
    my_strcpy(tmp_set, "MONEY:\n00000");
    tmp_set[11] = ((store->game->nb_money % 10) + '0');
    tmp_set[10] = (((store->game->nb_money / 10 ) % 10) + '0');
    tmp_set[9] = (((store->game->nb_money / 100 ) % 10) + '0');
    tmp_set[8] = (((store->game->nb_money / 1000 ) % 10) + '0');
    tmp_set[7] = (((store->game->nb_money / 10000 ) % 10) + '0');
    sfText_setString(store->game->text_money, tmp_set);
    tower_selector_text(store, store->game->select);
}