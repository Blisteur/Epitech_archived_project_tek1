/*
** EPITECH PROJECT, 2020
** struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

struct react_index
{
    sfIntRect rect1;
    sfIntRect rect2;
};

struct sprite
{
    sfSprite *sptbk;
    sfSprite *spt1;
    sfSprite *spt2;
    sfSprite *spt3;
    sfSprite *spt4;
    sfSprite *spt5;
    sfSprite *spt6;
    sfSprite *spt7;
    sfSprite *spt8;
    sfSprite *spt9;
    sfSprite *spt10;
    sfSprite *spt11;
    sfSprite *spt12;
    sfSprite *spt13;
    sfSprite *spt14;
    sfSprite *spt15;
    sfSprite *spt16;
    sfSprite *lf1;
    sfSprite *lf2;
    sfSprite *lf3;
};

struct texture
{
    sfTexture *txtbk;
    sfTexture *txt1;
    sfTexture *txt2;
    sfTexture *txt3;
    sfTexture *txt4;
    sfTexture *txt5;
    sfTexture *txt6;
    sfTexture *txt7;
    sfTexture *txt8;
    sfTexture *lf1;
    sfTexture *lf2;
    sfTexture *lf3;
    sfTexture *lf1_d;
    sfTexture *lf2_d;
    sfTexture *lf3_d;
};

struct pose
{
    sfVector2f init_pose_g;
    sfVector2f init_pose_d;
    sfVector2f move_pose_g;
    sfVector2f move_pose_d;
};

struct timer
{
    sfClock *clock_anim;
    sfTime time_anim;
    sfClock *clock_move;
    sfTime time_move;
    unsigned int t_in_ms;
};

struct score
{
    unsigned int score;
    int lock_score;
    unsigned int high_score;
};

struct game
{
    sfRenderWindow *win;
    sfVideoMode video_mode;
    sfEvent event;
    sfMusic *sound;
    int life;
    struct react_index *rect;
    struct sprite *sprite;
    struct texture *texture;
    struct pose *pose;
    struct timer *timer;
    struct score *score;

};

typedef struct game my_game;

#endif /* !MY_STRUCT */