/*
** EPITECH PROJECT, 2020
** struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

typedef enum game_mode
{
    MODE_MENU,
    MODE_GAME,
    MODE_PAUSE,
    MODE_END
}game_mode;

typedef enum mob_type
{
    CACTUS_TYPE_1,
    CACTUS_TYPE_2,
    BIRD
}mob_type;

typedef enum background_type
{
    BACKGROUND,
    THIRD_GROUND,
    SECOND_GROUND,
    FOREGROUND
}background_type;

typedef struct game
{
    enum game_mode mode;
    sfRenderWindow *win;
    sfVideoMode video_mode;
    int fullscreen;
    int fps;
    sfEvent evt;
    char *map;
    int nb_link_mob;
    struct player_s *player;
    struct mob_s *mob_list_first;
    struct mob_s *mob_list_last;
    struct menu_s *menu;
    struct parallax_s *bg[4];
    struct timer_s *timer;
    struct score_s *score;
    struct sound_s *sound;
    struct game_over_s *game_over;
}my_game;

typedef struct parallax_s
{
    enum background_type backgr;
    sfVector2f pose;
    sfVector2f poselp;
    sfSprite *sprite;
    sfSprite *spritelp;
    sfTexture *texture;
}parallax_t;

typedef struct menu_s
{
    sfVector2f pose;
    sfSprite *sprite;
    sfTexture *texture[5];
    sfVector2f hit_box_top_left[4];
    sfVector2f hit_box_bottom_right[4];
    int last;
    int touch;
}menu_t;

typedef struct score_s
{
    sfVector2f pose;
    sfText *hi_text;
    sfFont *font;
    sfColor color;
    char *text;
    int nb_co_score;
    char *hi_score;
}score_t;

typedef struct player_s
{
    sfVector2f pose;
    sfSprite *sprite;
    sfTexture *texture[2];
    sfIntRect rect;
    sfVector2f hit_box_bottom_right;
    int rect_value;
    int rect_max;
    int player_jump;
    float player_jump_speed;
}player_t;

typedef struct mob_s
{
    enum mob_type mob;
    sfVector2f pose;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int rect_value;
    int rect_max;
    sfVector2f hit_box_bottom_right;
    struct mob_s *next;
    struct mob_s *previous;
}mob_t;

typedef struct timer_s
{
    sfClock *clock_anim;
    sfTime time_anim;
    sfClock *clock_move;
    sfTime time_move;
    unsigned int t_in_ms;
    sfClock *clock_jump;
    sfTime time_jump;
    unsigned int gravity;
    int time_freeze;
    sfClock *clock_score;
    sfTime time_score;
}timer_st;

typedef struct sound_s
{
    sfMusic *music;
    sfMusic *jump;
    sfMusic *dead;
    sfMusic *score;
}sound_t;

typedef struct game_over_s
{
    sfVector2f pose;
    sfSprite *sprite;
    sfTexture *texture[2];
}game_over_t;

#endif /* !MY_STRUCT */