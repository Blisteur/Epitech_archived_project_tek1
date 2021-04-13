/*
** EPITECH PROJECT, 2021
** game mob type
** File description:
** file 1
*/

#include "my_defender.h"

void game_mob_base_soldat(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -2, 2 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = BASE_SOLDAT;
    mob->texture = sfTexture_createFromFile("sprites/unit_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 100;
    mob->damage = 100;
    mob->speed = 1;
    mob->money = 75;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}

void game_mob_up_soldat(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -2, 2 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = UP_SOLDAT;
    mob->texture = sfTexture_createFromFile("sprites/elite_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 200;
    mob->damage = 200;
    mob->speed = 1;
    mob->money = 150;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}

void game_mob_base_tank(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -4, 4 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = BASE_TANK;
    mob->texture = sfTexture_createFromFile("sprites/tank_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 500;
    mob->damage = 100;
    mob->speed = 1;
    mob->money = 300;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}

void game_mob_up_tank(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -4, 4 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = UP_TANK;
    mob->texture = sfTexture_createFromFile("sprites/cannon_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 50;
    mob->damage = 500;
    mob->speed = 1;
    mob->money = 450;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}

void game_mob_boss_tank(game_mob_link_t *mob, sfVector2f pos)
{
    sfVector2f scale = { -4, 4 };
    sfVector2f origine = { 16, 16 };
    sfIntRect rec = { 0, 0, 32, 32 };

    mob->type = BOSS_TANK;
    mob->texture = sfTexture_createFromFile("sprites/boss_32.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->rec = rec;
    sfSprite_setTextureRect(mob->sprite, mob->rec);
    mob->pos = pos;
    mob->life = 1000;
    mob->damage = 1000;
    mob->speed = 1;
    mob->money = 600;
    mob->cd = 0;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_scale(mob->sprite, scale);
    sfSprite_setOrigin(mob->sprite, origine);
}