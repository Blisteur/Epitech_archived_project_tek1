/*
** EPITECH PROJECT, 2021
** gameinit
** File description:
** file 1
*/

#include "my_defender.h"

void unload_game(my_struct_t *store)
{
    sfTexture_destroy(store->game->backtt);
    sfSprite_destroy(store->game->backsp);
    sfTexture_destroy(store->game->m_tower_t);
    sfSprite_destroy(store->game->m_tower_s);
    sfText_destroy(store->game->text_time);
    sfText_destroy(store->game->text_life);
    sfText_destroy(store->game->text_money);
    free_selector(store->game->select);
    destroy_game_sound(store);
    unload_pause_btn(store);
    destroy_clock(store);
    remove_all_mob(store);
    free_towers(store->game->towers);
    free(store->game);
    update_hi_score(store);
}

static void load_text_game(my_struct_t *store)
{
    int txt1[3] = {30, 1167, 10};
    int txt2[3] = {30, 1257, 10};
    int txt3[3] = {30, 1355, 10};

    store->game->text_time
    = init_text(store->fancyfont, "TIME:\n00:00", txt1, sfWhite);
    store->game->text_life
    = init_text(store->fancyfont, "LIFE:\n10000", txt2, sfWhite);
    store->game->text_money
    = init_text(store->fancyfont, "MONEY:\n00000", txt3, sfWhite);
}

static void load_back_game(my_struct_t *store)
{
    sfVector2f scale = { 4, 4 };
    sfVector2f pos = { 1412, 420 };
    sfVector2f origin = { 8, 32 };
    sfIntRect rect = { 0, 0, 16, 64 };

    store->game->backtt
    = sfTexture_createFromFile("./sprites/map_408_216.png", NULL);
    store->game->backsp = sfSprite_create();
    sfSprite_setTexture(store->game->backsp, store->game->backtt, sfFalse);
    sfSprite_setScale(store->game->backsp, scale);
    store->game->m_tower_t
    = sfTexture_createFromFile("./sprites/main_16_64.png", NULL);
    store->game->m_tower_s = sfSprite_create();
    sfSprite_setTexture(store->game->m_tower_s
    , store->game->m_tower_t, sfFalse);
    sfSprite_setTextureRect(store->game->m_tower_s, rect);
    sfSprite_setOrigin(store->game->m_tower_s, origin);
    sfSprite_setScale(store->game->m_tower_s, scale);
    sfSprite_setPosition(store->game->m_tower_s, pos);
}

void load_game(my_struct_t *store)
{
    store->game = malloc(sizeof(game_t));
    store->game->pause = malloc(sizeof(game_pause_t));
    load_back_game(store);
    store->game->stop = 0;
    store->game->mode = MODE_GAME;
    store->game->nb_money = 0;
    store->score->nb_cu_score = 0;
    store->game->first_mob = NULL;
    store->game->nb_mob = 0;
    store->game->nb_mob_money = 100;
    init_clock(store);
    load_text_game(store);
    store->game->select = load_selector(store);
    init_game_sound(store);
    load_pause_btn(store);
    store->game->towers = init_towers();
    update_money_txt(store, 500, '+');
}

void scene_changer_game(my_struct_t *store)
{
    unload_menu(store->menu);
    load_game(store);
    game_loop(store);
    unload_game(store);
    store->menu = load_menu(store);
}