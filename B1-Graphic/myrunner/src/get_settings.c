/*
** EPITECH PROJECT, 2020
** get_settings
** File description:
** file 1
*/

#include "../include/game.h"

int get_resolution(char *buff, my_game *store)
{
    int parsing = 0;

    store->video_mode.width = 0;
    store->video_mode.height = 0;
    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '{')
            store->video_mode.width = my_getnbr(buff + parsing + 1);
        if (buff[parsing] == '*')
            store->video_mode.height = my_getnbr(buff + parsing + 1);
    }
    if (store->video_mode.width <= 0 || store->video_mode.height <= 0 ||
        store->video_mode.width > 1920 || store->video_mode.height > 1080) {
        store->video_mode.width = 1920;
        store->video_mode.height = 1080;
    }
    return (parsing + 1);
}

int get_fullscreen(char *buff, my_game *store)
{
    int parsing = 0;

    store->fullscreen = 0;
    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '{')
            store->fullscreen = my_getnbr(buff + parsing + 1);
    }
    if (store->fullscreen != 0 && store->fullscreen != 1) {
        store->fullscreen = 0;
    }
    return (parsing + 1);
}

int get_bpp(char *buff, my_game *store)
{
    int parsing = 0;

    store->video_mode.bitsPerPixel = 0;
    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '{')
            store->video_mode.bitsPerPixel = my_getnbr(buff + parsing + 1);
    }
    if (store->video_mode.bitsPerPixel == 0)
        store->video_mode.bitsPerPixel = 32;
    return (parsing + 1);
}

int get_fps(char *buff, my_game *store)
{
    int parsing = 0;

    store->fps = 0;
    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '{')
            store->fps = my_getnbr(buff + parsing + 1);
    }
    if (store->fps == 0)
        store->fps = 64;
    store->fps = 64;
    return (parsing + 1);
}

void get_settings(my_game *store)
{
    int fd = open("src/file/settings.txt", O_RDONLY);
    char buff[501];
    int tmp = 0;

    buff[500] = '\0';
    read(fd, buff, 500);
    tmp += get_resolution(buff + tmp, store);
    tmp += get_fullscreen(buff + tmp, store);
    tmp += get_bpp(buff + tmp, store);
    get_fps(buff + tmp, store);
    close(fd);
}