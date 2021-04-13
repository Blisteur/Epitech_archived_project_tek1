/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-mydefender-hildebert.jeanjean
** File description:
** options_func.c
*/

#include "my_defender.h"

void fullscreen(my_struct_t *store)
{
    if (store->settings->fullscreen == 0) {
        store->settings->fullscreen = 1;
        sfText_setColor(store->menu->options->fullscreen->text, sfGreen);
        sfText_setString(store->menu->options->fullscreen->text,
        "FULLSCREEN\n        X");
    }
    else {
        store->settings->fullscreen = 0;
        sfText_setColor(store->menu->options->fullscreen->text, sfRed);
        sfText_setString(store->menu->options->fullscreen->text, "FULLSCREEN");
    }
    store->settings->is_modified = 1;
    apply_settings(store);
}

void set_six(my_struct_t *store)
{
    sfText_setColor(store->menu->options->six->text, sfGreen);
    sfText_setColor(store->menu->options->seven->text, sfRed);
    sfText_setColor(store->menu->options->ten->text, sfRed);
    store->settings->resolution[0] = 800;
    store->settings->resolution[1] = 600;
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
    store->settings->is_modified = 1;
    apply_settings(store);
}

void set_seven(my_struct_t *store)
{
    sfText_setColor(store->menu->options->six->text, sfRed);
    sfText_setColor(store->menu->options->seven->text, sfGreen);
    sfText_setColor(store->menu->options->ten->text, sfRed);
    store->settings->resolution[0] = 1280;
    store->settings->resolution[1] = 720;
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
    store->settings->is_modified = 1;
    apply_settings(store);
}

void set_ten(my_struct_t *store)
{
    sfText_setColor(store->menu->options->six->text, sfRed);
    sfText_setColor(store->menu->options->seven->text, sfRed);
    sfText_setColor(store->menu->options->ten->text, sfGreen);
    store->settings->resolution[0] = 1920;
    store->settings->resolution[1] = 1080;
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
    store->settings->is_modified = 1;
    apply_settings(store);
}