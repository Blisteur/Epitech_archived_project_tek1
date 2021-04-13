/*
** EPITECH PROJECT, 2021
** menu_settings
** File description:
** file 1
*/

#include "my_defender.h"

void display_menu_settings(menu_settings_t *options, my_struct_t *store)
{
    sfRenderWindow_drawRectangleShape(store->win, options->back, NULL);
    sfRenderWindow_drawText(store->win, options->title, NULL);
    draw_btn(store, options->fullscreen);
    draw_btn(store, options->six);
    draw_btn(store, options->seven);
    draw_btn(store, options->ten);
    draw_btn(store, options->thirty_fps);
    draw_btn(store, options->sixty_fps);
    draw_btn(store, options->master_plus);
    draw_btn(store, options->master_moin);
    draw_btn(store, options->sound_plus);
    draw_btn(store, options->sound_moin);
    sfRenderWindow_drawText(store->win, options->master_text, NULL);
    sfRenderWindow_drawText(store->win, options->sound_text, NULL);
}

sfRectangleShape *set_option_back(void)
{
    sfRectangleShape *back = sfRectangleShape_create();
    sfUint8 rgb[3] = {102, 51, 0};
    sfColor splash = sfColor_fromRGB(rgb[0], rgb[1], rgb[2]);
    sfUint8 fill[3] = {255, 178, 102};
    sfColor filler = sfColor_fromRGB(fill[0], fill[1], fill[2]);
    sfVector2f pos;

    pos.x = 1632 / 2;
    pos.y = 0;
    sfRectangleShape_setPosition(back, pos);
    pos.y = 864;
    sfRectangleShape_setSize(back, pos);
    sfRectangleShape_setFillColor(back, filler);
    sfRectangleShape_setOutlineColor(back, splash);
    sfRectangleShape_setOutlineThickness(back, 5.0);
    return (back);
}

menu_settings_t *load_menu_settings(my_struct_t *store)
{
    menu_settings_t *options = malloc(sizeof(menu_settings_t));
    int units[3] = {80, 1100, 0};

    options->active = 0;
    options->back = set_option_back();
    options->title = init_text(store->fancyfont, "SETTINGS", units, sfWhite);
    options = settings_buttons(store, options);
    return (options);
}

void unload_menu_settings(menu_settings_t *options)
{
    sfRectangleShape_destroy(options->back);
    sfText_destroy(options->title);
    sfText_destroy(options->master_text);
    sfText_destroy(options->sound_text);
    unload_button(options->fullscreen);
    unload_button(options->six);
    unload_button(options->seven);
    unload_button(options->ten);
    unload_button(options->thirty_fps);
    unload_button(options->sixty_fps);
    unload_button(options->master_plus);
    unload_button(options->master_moin);
    unload_button(options->sound_plus);
    unload_button(options->sound_moin);
    free(options);
}

void settings_switch(my_struct_t *store)
{
    if (store->menu->options->active != 1)
        store->menu->options->active = 1;
    else
        store->menu->options->active = 0;
}