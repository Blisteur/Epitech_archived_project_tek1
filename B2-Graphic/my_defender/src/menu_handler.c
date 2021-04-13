/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** menu_handler.c
*/

#include "my_defender.h"

void quit_window(struct my_struct_s *store)
{
    sfRenderWindow_close(store->win);
}

struct menu_s *load_menu(struct my_struct_s *store)
{
    struct menu_s *menu = malloc(sizeof(menu_t));
    int units[3] = {150, 815, 220};
    sfVector2f scale = {4, 4};

    menu->title = init_text(store->fancyfont, "El Defender",
                                    units, sfWhite);
    menu->backtt = sfTexture_createFromFile("./sprites/menu_back.png", NULL);
    menu->backsp = sfSprite_create();
    sfSprite_setTexture(menu->backsp, menu->backtt, sfFalse);
    sfSprite_setScale(menu->backsp, scale);
    menu = load_menu_buttons(menu, store);
    load_manual(menu);
    menu->options = load_menu_settings(store);
    return (menu);
}

void unload_menu(struct menu_s *menu)
{
    sfTexture_destroy(menu->backtt);
    sfSprite_destroy(menu->backsp);
    sfTexture_destroy(menu->howtt);
    sfSprite_destroy(menu->howto);
    sfText_destroy(menu->title);
    unload_button(menu->start);
    unload_button(menu->quit);
    unload_button(menu->settings);
    unload_button(menu->manual);
    unload_menu_settings(menu->options);
    free(menu);
}