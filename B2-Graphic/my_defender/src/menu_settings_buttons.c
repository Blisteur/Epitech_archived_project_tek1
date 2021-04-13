/*
** EPITECH PROJECT, 2021
** menu_settings_buttons
** File description:
** file 1
*/

#include "my_defender.h"

void interact_options(my_struct_t *store)
{
    interact_with_button(store->menu->options->fullscreen, store->evt, store);
    interact_with_button(store->menu->options->six, store->evt, store);
    interact_with_button(store->menu->options->seven, store->evt, store);
    interact_with_button(store->menu->options->ten, store->evt, store);
    interact_with_button(store->menu->options->thirty_fps, store->evt, store);
    interact_with_button(store->menu->options->sixty_fps, store->evt, store);
    interact_with_button(store->menu->options->master_plus, store->evt, store);
    interact_with_button(store->menu->options->master_moin, store->evt, store);
    interact_with_button(store->menu->options->sound_plus, store->evt, store);
    interact_with_button(store->menu->options->sound_moin, store->evt, store);
}

static void base_option(my_struct_t *store, menu_settings_t *options)
{
    sfText_setColor(options->six->text, sfRed);
    sfText_setColor(options->seven->text, sfRed);
    sfText_setColor(options->ten->text, sfRed);
    sfText_setColor(options->thirty_fps->text, sfRed);
    sfText_setColor(options->sixty_fps->text, sfRed);
    if (store->settings->resolution[0] == 800 &&
    store->settings->resolution[1] == 600)
        sfText_setColor(options->six->text, sfGreen);
    if (store->settings->resolution[0] == 1280 &&
    store->settings->resolution[1] == 720)
        sfText_setColor(options->seven->text, sfGreen);
    if (store->settings->resolution[0] == 1920 &&
    store->settings->resolution[1] == 1080)
        sfText_setColor(options->ten->text, sfGreen);
    if (store->settings->fps == 30)
        sfText_setColor(options->thirty_fps->text, sfGreen);
    if (store->settings->fps == 60)
        sfText_setColor(options->sixty_fps->text, sfGreen);
}

void custom_settings_buttons(my_struct_t *store, menu_settings_t *options)
{
    int btn9[3] = {42, 1106, 600};
    int btn10[3] = {42, 1362, 600};
    int txt1[3] = {42, 850, 475};
    int txt2[3] = {42, 850, 625};

    options->master_text = init_text(store->fancyfont, "tmp", txt1, sfWhite);
    options->sound_plus = load_button("  Sound +", btn9, sound_vl_p, store);
    options->sound_moin = load_button("  Sound -", btn10, sound_vl_m, store);
    options->sound_text = init_text(store->fancyfont, "tmp", txt2, sfWhite);
    if (store->settings->fullscreen == 1) {
        sfText_setColor(options->fullscreen->text, sfGreen);
        sfText_setString(options->fullscreen->text, "FULLSCREEN\n        X");
    } else {
        sfText_setColor(options->fullscreen->text, sfRed);
        sfText_setString(options->fullscreen->text, "FULLSCREEN");
    }
    base_option(store, options);
    settings_get_volume(store, options);
}

menu_settings_t *settings_buttons(my_struct_t *store, menu_settings_t *options)
{
    int btn1[3] = {40, 850, 150};
    int btn2[3] = {70, 850, 300};
    int btn3[3] = {70, 1106, 300};
    int btn4[3] = {70, 1362, 300};
    int btn5[3] = {42, 1106, 150};
    int btn6[3] = {42, 1362, 150};
    int btn7[3] = {42, 1106, 450};
    int btn8[3] = {42, 1362, 450};


    options->fullscreen = load_button(" FULLSCREEN", btn1, fullscreen, store);
    options->six = load_button(" 600p", btn2, set_six, store);
    options->seven = load_button(" 720p", btn3, set_seven, store);
    options->ten = load_button(" 1080p", btn4, set_ten, store);
    options->thirty_fps = load_button("    30FPS", btn5, thirty_fps, store);
    options->sixty_fps = load_button("    60FPS", btn6, sixty_fps, store);
    options->master_plus = load_button("  Master +", btn7, master_vl_p, store);
    options->master_moin = load_button("  Master -", btn8, master_vl_m, store);
    custom_settings_buttons(store, options);
    return (options);
}