/*
** EPITECH PROJECT, 2021
** get_settings
** File description:
** file 1
*/

#include "my_defender.h"

void defaut_settings(my_struct_t *store)
{
    store->settings->resolution[0] = 600;
    store->settings->resolution[1] = 600;
    store->settings->fullscreen = 0;
    store->settings->bpp = 32;
    store->settings->fps = 60;
    store->settings->volume[0] = 100;
    store->settings->volume[1] = 100;
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
    store->settings->video_mode.bitsPerPixel = store->settings->bpp;
}

void print_active_param(my_struct_t *store)
{
    my_printf("/////////////////////////\n");
    my_printf("resolution: %dx%d\n", store->settings->resolution[0]
                                    , store->settings->resolution[1]);
    my_printf("fullscreen: %d\n", store->settings->fullscreen);
    my_printf("bpp: %d\n", store->settings->bpp);
    my_printf("fps: %d\n", store->settings->fps);
    my_printf("master volume: %d\n", store->settings->volume[0]);
    my_printf("sound volume: %d\n", store->settings->volume[1]);
    my_printf("/////////////////////////\n");
}

FILE *open_settings_file(my_struct_t *store)
{
    FILE *fp = NULL;

    fp = fopen("src/files/settings.txt", "r");
    if (fp == NULL) {
        defaut_settings(store);
        return (NULL);
    }
    return (fp);
}

void get_settings(my_struct_t *store)
{
    char *buff = NULL;
    size_t buff_size = 0;
    FILE *fp = open_settings_file(store);
    int lenght = 0;

    if (fp == NULL) {
        return;
    }
    for (int nb = 0; nb < 6; nb += 1) {
        lenght =  getline(&buff, &buff_size, fp);
        if (buff == NULL || lenght == -1) {
            defaut_settings(store);
            fclose(fp);
            return;
        }
        store->settings->ptr[nb](store, buff);
        buff_size = 0;
        free(buff);
    }
    fclose(fp);
}