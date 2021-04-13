/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** file 1
*/

#include "include/game.h"

void manage_mouse_click(my_game *store, sfEvent evt)
{
    hit_box_mob_type_1(store, evt.mouseButton.x, evt.mouseButton.y);
    hit_box_mob_type_2(store, evt.mouseButton.x, evt.mouseButton.y);
    hit_box_mob_type_3(store, evt.mouseButton.x, evt.mouseButton.y);
    hit_box_mob_type_4(store, evt.mouseButton.x, evt.mouseButton.y);
}

void analyse_events(my_game *store, sfRenderWindow *window, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(window, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (evt.type == sfEvtMouseButtonPressed && evt.mouseButton.button == 0)
            manage_mouse_click(store, evt);
    }
}

void init_game(my_game *store)
{
    store->video_mode.width = defaut_width;
    store->video_mode.height = defaut_height;
    store->video_mode.bitsPerPixel = defaut_bitsPerPixel;
    store->sound = sfMusic_createFromFile("src/mt.wav");
    sfMusic_play(store->sound);
    sfMusic_setLoop(store->sound, sfTrue);
    sfMusic_setVolume(store->sound, 25);
    store->score->score = 0;
    store->score->lock_score = 0;
    store->score->high_score = verif_high_score();
    store->life = 3;
    store->timer->t_in_ms = 100000;
    store->timer->clock_anim = sfClock_create();
    store->timer->clock_move = sfClock_create();
    store->win = sfRenderWindow_create(store->video_mode,
                                        N_GAME, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(store->win, 60);
    create_texture_and_sprite(store);
}

void create_texture_and_sprite(my_game *store)
{
    create_texture(store);
    create_sprite(store);
    set_pose_sprite(store);
    rect_init(store);
    set_texture(store);
    set_texture_rect(store);
    set_life_texture(store);
    set_life_sprite(store);
    sfSprite_setTexture(store->sprite->sptbk, store->texture->txtbk, sfTrue);
    sfSprite_setPosition(store->sprite->spt1, store->pose->init_pose_g);
    sfSprite_setPosition(store->sprite->spt2, store->pose->init_pose_d);
}

void game(void)
{
    my_game *store = malloc(sizeof(my_game));

    store->rect = malloc(sizeof(struct react_index));
    store->pose = malloc(sizeof(struct pose));
    store->texture = malloc(sizeof(struct texture));
    store->sprite = malloc(sizeof(struct sprite));
    store->timer = malloc(sizeof(struct timer));
    store->score = malloc(sizeof(struct score));
    init_game(store);
    while (sfRenderWindow_isOpen(store->win)) {
        verif_score(store);
        drawsprite(store);
        timer(store);
        analyse_events(store, store->win, store->event);
        sfRenderWindow_display(store->win);
    }
    destroy_game(store);
}