/*
** EPITECH PROJECT, 2021
** make pause
** File description:
** file 1
*/

#include "../include/game.h"

void make_pause(my_game *store)
{
    char *tmp = malloc(sizeof(char) * 17);
    sfVector2f tmp_pose = {900, 100};

    tmp[16] = '\0';
    my_strcpy(tmp, "PAUSE");
    sfText_setString(store->score->hi_text, tmp);
    sfText_setPosition(store->score->hi_text, tmp_pose);
    sfRenderWindow_drawText(store->win, store->score->hi_text, NULL);
    sfText_setString(store->score->hi_text, store->score->text);
    sfText_setPosition(store->score->hi_text, store->score->pose);
    store->timer->time_freeze = 0;
    sfMusic_pause(store->sound->music);
    free(tmp);
}

void pause_event(my_game *store)
{
    if (store->evt.key.code == sfKeyEscape
    && store->evt.type == sfEvtKeyReleased) {
        if (store->mode == MODE_PAUSE)
            store->mode = MODE_GAME;
        else if (store->mode == MODE_GAME)
            store->mode = MODE_PAUSE;
        }
}