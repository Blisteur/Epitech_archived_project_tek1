/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** .h
*/

#ifndef MY_DEFENDER
#define MY_DEFENDER

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "struct.h"
#include "my.h"

void game();
void init_game(my_struct_t *store);
void destroy_game(my_struct_t *store);
void get_settings(my_struct_t *store);
void print_active_param(my_struct_t *store);
void set_resolution(my_struct_t *store, char *buff);
void set_fullsreen(my_struct_t *store, char *buff);
void set_bpp(my_struct_t *store, char *buff);
void set_fps(my_struct_t *store, char *buff);
void set_master_volume(my_struct_t *store, char *buff);
void set_sound_volume(my_struct_t *store, char *buff);
void init_settings(my_struct_t *store);
void write_settings(my_struct_t *store);
void init_score(my_struct_t *store);
void destroy_score(my_struct_t *store);

void get_high_score(my_struct_t *store);
void update_hi_score(my_struct_t *store);
void write_score(my_struct_t *store);

struct menu_s *load_menu(struct my_struct_s *store);
void unload_menu(struct menu_s *menu);
void display_menu(struct my_struct_s *store);
sfSprite *init_sprite(int sizes[5], sfIntRect *crop, sfTexture *tt);
sfText *init_text(sfFont *font, char *txt, int units[3], sfColor color);
void quit_window(struct my_struct_s *store);

void interact_with_button(struct button_s *btn, sfEvent evt, my_struct_t *stor);
int mouse_over_button(sfIntRect pos, my_struct_t *store);
struct menu_s *load_menu_buttons(struct menu_s *menu, struct my_struct_s *stor);
struct button_s *load_button(char *txt, int un[3], void *pt, my_struct_t *st);
void unload_button(struct button_s *button);
void draw_btn(my_struct_t *store, button_t *btn);

void analyse_events(my_struct_t *store);
void analyse_menu(my_struct_t *store);

void load_manual(struct menu_s *menu);
void load_game(my_struct_t *store);
void game_loop(my_struct_t *store);
void scene_changer_game(my_struct_t *store);

void settings_switch(my_struct_t *store);
void manual_button(my_struct_t *store);
void display_menu_settings(menu_settings_t *options, my_struct_t *store);
menu_settings_t *load_menu_settings(my_struct_t *store);
void unload_menu_settings(menu_settings_t *options);

void pause_event(my_struct_t *store);
void pause_mode(my_struct_t *store);
void pause_button_quit_to_menu(my_struct_t *store);
void pause_button_resume(my_struct_t *store);
void load_pause_btn(my_struct_t *store);
void unload_pause_btn(my_struct_t *store);
void display_pause(sfRenderWindow *win, game_pause_t *pause);
void pause_button_exit(my_struct_t *store);

void init_clock(my_struct_t *store);
void destroy_clock(my_struct_t *store);
void timer(my_struct_t *store);

menu_settings_t *settings_buttons(my_struct_t *store, menu_settings_t *options);
void settings_get_volume(my_struct_t *store, menu_settings_t *options);
void interact_options(my_struct_t *store);
void fullscreen(my_struct_t *store);
void set_six(my_struct_t *store);
void set_seven(my_struct_t *store);
void set_ten(my_struct_t *store);
void thirty_fps(my_struct_t *store);
void sixty_fps(my_struct_t *store);
void master_vl_p(my_struct_t *store);
void master_vl_m(my_struct_t *store);
void sound_vl_p(my_struct_t *store);
void sound_vl_m(my_struct_t *store);

void apply_settings(my_struct_t *store);

void update_time_txt(my_struct_t *store);
void update_life_txt(my_struct_t *store, int nb);
void update_money_txt(my_struct_t *store, int nb, char c);

struct select_s *load_selector(my_struct_t *store);
sfIntRect set_intrect(int left, int top, int width, int height);
struct select_s *apply_prices(int prices[8], select_t *select);
struct select_s *load_select_texts(struct select_s *select, my_struct_t *store);
void free_selector(select_t *select);
void show_selector(my_struct_t *store, select_t *select);
void click_selector(my_struct_t *store, select_t *select);

void init_audio(my_struct_t *store);
void destroy_audio(my_struct_t *store);
void init_game_sound(my_struct_t *store);
void destroy_game_sound(my_struct_t *store);
void audio_run_hurt(my_struct_t *store);
void audio_run_click(my_struct_t *store);
void audio_run_place_tower(my_struct_t *store);

// mob handler
game_mob_link_t *add_mob_link(my_struct_t *store, game_mob_link_t *p, void *type_mob, sfVector2f pos);
void remove_mob_link(my_struct_t *store, game_mob_link_t *p);
void debug_print_mob(my_struct_t *store);
void game_mob_base_soldat(game_mob_link_t *mob, sfVector2f pos);
void game_mob_up_soldat(game_mob_link_t *mob, sfVector2f pos);
void game_mob_base_tank(game_mob_link_t *mob, sfVector2f pos);
void game_mob_up_tank(game_mob_link_t *mob, sfVector2f pos);
void game_mob_boss_tank(game_mob_link_t *mob, sfVector2f pos);
void game_mob_missile(game_mob_link_t *mob, sfVector2f pos);
void remove_all_mob(my_struct_t *store);
void game_mob_anim(my_struct_t *store);
void game_mob_move(my_struct_t *store);
void verif_life(my_struct_t *store);
void verif_life_mob(my_struct_t *store, game_mob_link_t *mob);
void game_spawn_mob(my_struct_t *store, int tmp);
void verif_mob_speed(my_struct_t *store);

struct select_s *load_selector(my_struct_t *store);
void free_selector(select_t *select);
struct select_s *load_select_texts(struct select_s *select, my_struct_t *store);
struct select_s *apply_prices(int prices[8], select_t *select);
sfIntRect set_intrect(int left, int top, int width, int height);
void tower_selector(my_struct_t *store, select_t *select);
void show_selector(my_struct_t *store, select_t *select);
void tower_selector_text(my_struct_t *store, select_t *select);
void click_selector(my_struct_t *store, select_t *select);
void update_selector(select_t *select);
void selector_pos(my_struct_t *store, select_t *select);
sfRectangleShape *load_stop(void);

struct tower_s *init_towers(void);
void free_towers(tower_t *towers);
void free_tower_list(struct list_s **list);
void add_tower(list_t **list, tower_t *tower, select_t *select, my_struct_t *s);
sfSprite *add_tower_sprite(tower_t *towers, select_t *select, list_t *list);
void show_selector(my_struct_t *store, select_t *select);

int can_place_tower(select_t *select, tower_t *towers);
int is_tower_conflicting(select_t *select, list_t **list);
sfRectangleShape *load_stop(void);
void update_stop(select_t *select);
void selector_stop(select_t *select);
void change_mouse_pos(my_struct_t *store, select_t *select);

void tower_act(my_struct_t *store, list_t **tower, tower_t *towers);
void tower_has_power(my_struct_t *store, list_t *tower);
int in_range(sfVector2f center, int radius, sfVector2f target);

//Tower powers:
void single_attack(my_struct_t *store, list_t *list, tower_t *towers);
void snipe_healthiest(my_struct_t *store, list_t *list, tower_t *towers);
void multi_attack(my_struct_t *store, list_t *list, tower_t *towers);
void nuke_launcher(my_struct_t *store, list_t *list, tower_t *towers);
void slow_units(my_struct_t *store, list_t *list, tower_t *towers);
void stun_units(my_struct_t *store, list_t *list, tower_t *towers);
void power_radius(my_struct_t *store, list_t *list, tower_t *towers);
void power_all(my_struct_t *store, list_t *tower, tower_t *towers);

#endif /* !MY_DEFENDER */