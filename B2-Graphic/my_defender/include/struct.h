/*
** EPITECH PROJECT, 2021
** struct
** File description:
** .h
*/

#ifndef STRUCT
#define STRUCT

typedef struct my_struct_s
{
    sfRenderWindow *win;
    sfEvent evt;
    sfView *cam;
    sfFont *fancyfont;
    sfFont *buttonfont;
    struct settings_s *settings;
    struct score_s *score;
    struct menu_s *menu;
    struct game_s *game;
    struct audio_s *audio;
}my_struct_t;

typedef struct settings_s
{
    int resolution[2];
    int fullscreen;
    int fps;
    int bpp;
    int volume[2];
    sfVideoMode video_mode;
    void (*ptr[6])(my_struct_t *, char *);
    int is_modified;
}settings_t;

typedef struct menu_settings_s
{
    int active;
    sfRectangleShape *back;
    sfText *title;
    struct button_s *fullscreen;
    struct button_s *six;
    struct button_s *seven;
    struct button_s *ten;
    struct button_s *thirty_fps;
    struct button_s *sixty_fps;
    struct button_s *master_plus;
    struct button_s *master_moin;
    struct button_s *sound_plus;
    struct button_s *sound_moin;
    sfText *master_text;
    sfText *sound_text;
}menu_settings_t;

typedef enum game_mob_type_s
{
    BASE_SOLDAT,
    UP_SOLDAT,
    BASE_TANK,
    UP_TANK,
    BOSS_TANK,
    MISSILE
}game_mob_type_t;

typedef struct game_mob_link_s
{
    enum game_mob_type_s type;
    int life;
    int damage;
    float speed;
    int money;
    float cd;
    sfVector2f pos;
    sfIntRect rec;
    sfSprite *sprite;
    sfTexture *texture;
    struct game_mob_link_s *next;
    struct game_mob_link_s *previous;
}game_mob_link_t;

typedef struct list_s
{
    sfSprite *sprite;
    sfIntRect box;
    sfVector2f pos;

    int id;
    float cd;
    int type;
    int power;
    struct list_s *next;
}list_t;

typedef struct tower_s
{
    sfTexture *big;
    sfTexture *small;
    sfClock *clock;
    float elapsed;

    int all;
    void (*ptr[8])(struct my_struct_s *, struct list_s *
                , struct tower_s *towers);
    struct list_s *list;
}tower_t;

typedef struct menu_s
{
    sfSprite *backsp;
    sfSprite *howto;
    sfTexture *howtt;
    sfTexture *backtt;
    sfText *title;
    struct menu_settings_s *options;
    struct button_s *start;
    struct button_s *manual;
    struct button_s *settings;
    struct button_s *quit;
}menu_t;

typedef struct button_s
{
    int pressed;
    sfIntRect rect;
    sfIntRect pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    int (*ptr)(struct my_struct_s *);
}button_t;

typedef struct conf_s
{
    int *dmg;
    int *range;
}conf_t;

typedef struct score_s
{
    sfVector2f pose;
    sfText *hi_text;
    int nb_cu_score;
    char *char_hi_score;
}score_t;

typedef struct audio_s
{
    sfMusic *master_music;
    sfSoundBuffer *hurt_sound_buffer;
    sfSoundBuffer *click_sound_buffer;
    sfSoundBuffer *place_tower_sound_buffer;
    sfSound *hurt_sound;
    sfSound *click_sound;
    sfSound *place_tower_sound;
}audio_t;

typedef struct game_clock_s
{
    sfClock *anim_clock;
    sfTime anim_time;
    int anim_t_ms;
    sfClock *move_clock;
    sfTime move_time;
    int move_t_ms;
    sfClock *cu_time_clock;
    sfTime cu_time_time;
    int cu_time_t_ms;
    int time_freeze;
}game_clock_t;

typedef enum game_mode
{
    MODE_GAME,
    MODE_PAUSE,
    MODE_END
}game_mode;

typedef struct game_pause_s
{
    struct button_s *resume;
    struct button_s *quit_to_menu;
    struct button_s *exit;
}game_pause_t;

typedef struct select_s
{
    int selected;
    int can_place;

    sfRectangleShape *stop;
    sfIntRect pos;
    sfTexture *small;
    sfTexture *big;
    sfSprite *sprite;
    sfIntRect buy[8];
    sfText *price[8];
    int prices[8];
}select_t;

typedef struct game_s
{
    sfSprite *backsp;
    sfTexture *backtt;
    sfSprite *m_tower_s;
    sfTexture *m_tower_t;
    int stop;
    struct game_clock_s *clock;
    struct select_s *select;
    enum game_mode mode;
    sfText *text_time;
    sfText *text_life;
    sfText *text_money;
    struct game_pause_s *pause;
    int nb_money;
    int nb_mob;
    int nb_mob_money;
    struct game_mob_link_s *first_mob;
    struct tower_s *towers;
}game_t;


#endif /* !STRUCT */