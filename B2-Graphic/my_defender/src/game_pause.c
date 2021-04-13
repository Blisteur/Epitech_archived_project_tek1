/*
** EPITECH PROJECT, 2021
** pause
** File description:
** file 1
*/

#include "my_defender.h"

void display_pause(sfRenderWindow *win, game_pause_t *pause)
{
    sfRenderWindow_drawSprite(win, pause->resume->sprite, NULL);
    sfRenderWindow_drawSprite(win, pause->quit_to_menu->sprite, NULL);
    sfRenderWindow_drawSprite(win, pause->exit->sprite, NULL);
    sfRenderWindow_drawText(win, pause->resume->text, NULL);
    sfRenderWindow_drawText(win, pause->quit_to_menu->text, NULL);
    sfRenderWindow_drawText(win, pause->exit->text, NULL);
    sfRenderWindow_display(win);
}

void pause_event(my_struct_t *store)
{
    if (store->game->mode == MODE_PAUSE) {
        interact_with_button(store->game->pause->resume, store->evt, store);
        interact_with_button(store->game->pause->quit_to_menu
                            , store->evt, store);
        interact_with_button(store->game->pause->exit, store->evt, store);
    }
    if (store->evt.key.code == sfKeyEscape
    && store->evt.type == sfEvtKeyReleased) {
        if (store->evt.key.code == sfKeyEscape
            && store->game->mode == MODE_GAME) {
            store->game->mode = MODE_PAUSE;
            sfMusic_pause(store->audio->master_music);
        }
        else if (store->evt.key.code == sfKeyEscape
            && store->game->mode == MODE_PAUSE) {
            store->game->mode = MODE_GAME;
            sfMusic_play(store->audio->master_music);
        }
    }
}

void load_pause_btn(my_struct_t *store)
{
    int butn1[3] = {50, 300, 200};
    int butn2[3] = {50, 300, 400};
    int butn3[3] = {50, 300, 600};

    store->game->pause->resume =
        load_button("RESUME", butn1, pause_button_resume, store);
    store->game->pause->quit_to_menu =
        load_button("MENU", butn2, pause_button_quit_to_menu, store);
    store->game->pause->exit =
        load_button("EXIT GAME", butn3, pause_button_exit, store);
}

void unload_pause_btn(my_struct_t *store)
{
    unload_button(store->game->pause->resume);
    unload_button(store->game->pause->quit_to_menu);
    unload_button(store->game->pause->exit);
    free(store->game->pause);
}

void pause_mode(my_struct_t *store)
{
    int pause_nb[3] = { 50, 730, 200 };
    sfText *pause = init_text(store->buttonfont, "PAUSE", pause_nb, sfBlack);

    store->game->clock->time_freeze = 0;
    sfRenderWindow_drawText(store->win, pause, NULL);
    sfRenderWindow_display(store->win);
    sfText_destroy(pause);
}