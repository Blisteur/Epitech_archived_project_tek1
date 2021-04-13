/*
** EPITECH PROJECT, 2021
** struct_handler
** File description:
** file 1
*/

#include "my_defender.h"

sfView *set_camera_size(sfView *cam)
{
    int x = 1632;
    int y = 864;
    sfVector2f size;

    size.x = x;
    size.y = y;
    sfView_setSize(cam, size);
    return (cam);
}

sfView *load_cam(void)
{
    sfFloatRect size;
    sfView *cam;
    sfVector2f pos;

    size.top = 0;
    size.left = 0;
    size.height = 1632;
    size.width = 864;
    cam = sfView_createFromRect(size);
    size.height = 1;
    size.width = 1;
    sfView_setViewport(cam, size);
    set_camera_size(cam);
    pos.x = 1632 / 2;
    pos.y = 864 / 2;
    sfView_setCenter(cam, pos);
    return (cam);
}

void init_game(my_struct_t *store)
{
    init_settings(store);
    get_settings(store);
    if (store->settings->fullscreen == 0)
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_DEFENDER", sfResize | sfClose, NULL);
    else
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_DEFENDER", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(store->win, store->settings->fps);
    store->fancyfont = sfFont_createFromFile("src/files/Mintmolly.ttf");
    store->buttonfont = sfFont_createFromFile("src/files/Pixellari.ttf");
    store->menu = load_menu(store);
    store->cam = load_cam();
    sfRenderWindow_setView(store->win, store->cam);
    init_score(store);
    init_audio(store);
}

void destroy_game(my_struct_t *store)
{
    if (store->settings->is_modified == 1)
        write_settings(store);
    if (store->score->nb_cu_score > 0)
        write_score(store);
    unload_menu(store->menu);
    sfFont_destroy(store->buttonfont);
    sfFont_destroy(store->fancyfont);
    sfRenderWindow_destroy(store->win);
    destroy_score(store);
    destroy_audio(store);
    sfView_destroy(store->cam);
    free(store->settings);
    free(store);
}