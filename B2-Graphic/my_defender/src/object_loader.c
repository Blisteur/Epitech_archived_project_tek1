/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sprite_loader.c
*/

#include "my_defender.h"

sfSprite *init_sprite(int sizes[5], sfIntRect *crop, sfTexture *tt)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect temp;
    sfVector2f scale;

    sfSprite_setTexture(sprite, tt, sfFalse);
    crop->height = sizes[0];
    crop->width = sizes[1];
    crop->left = sizes[2];
    crop->top = sizes[3];
    temp = *crop;
    sfSprite_setTextureRect(sprite, temp);
    scale.x = sizes[4];
    scale.y = sizes[4];
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfText *init_text(sfFont *font, char *txt, int units[3], sfColor color)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = units[1];
    pos.y = units[2];
    sfText_setColor(text, color);
    sfText_setString(text, txt);
    sfText_setCharacterSize(text, units[0]);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    return (text);
}

struct button_s *load_button(char *txt, int un[3], void *pt, my_struct_t *st)
{
    struct button_s *button = malloc(sizeof(button_t));
    int sizes[5] = {16, 32, 0, 0, 8};

    sfVector2f pos;
    pos.x = un[1];
    pos.y = un[2];
    button->pos.left = un[1];
    button->pos.top = un[2];
    button->pos.height = 16 * 8;
    button->pos.width = 32 * 8;
    button->texture = sfTexture_createFromFile("./sprites/button_32_16.png",
                                                                        NULL);
    button->sprite = init_sprite(sizes, &button->rect, button->texture);
    button->text = init_text(st->buttonfont, txt, un, sfWhite);
    sfSprite_setPosition(button->sprite, pos);
    button->ptr = pt;
    button->pressed = 0;
    return (button);
}

void unload_button(struct button_s *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    sfText_destroy(button->text);
    free(button);
}

struct menu_s *load_menu_buttons(struct menu_s *menu, struct my_struct_s *stor)
{
    int butn1[3] = {50, 300, 200};
    int butn2[3] = {50, 300, 400};
    int butn3[3] = {50, 300, 600};
    int butn4[3] = {50, 10, 400};
    void *ptr = quit_window;

    menu->settings = load_button("SETTINGS", butn2, settings_switch, stor);
    menu->quit = load_button("QUIT", butn3, ptr, stor);
    menu->start = load_button("START", butn1, scene_changer_game, stor);
    menu->manual = load_button("MANUAL", butn4, manual_button, stor);
    return (menu);
}