/*
** EPITECH PROJECT, 2021
** game mob type
** File description:
** file 2
*/

#include "my_defender.h"

void game_mob_missile(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -4, 4 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = MISSILE;
    mob->texture = sfTexture_createFromFile("sprites/missile_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 200;
    mob->damage = 200;
    mob->speed = 2;
    mob->money = 525;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}