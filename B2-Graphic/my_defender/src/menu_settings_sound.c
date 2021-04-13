/*
** EPITECH PROJECT, 2021
** menu settings
** File description:
** file 1
*/

#include "my_defender.h"

void settings_get_volume(my_struct_t *store, menu_settings_t *options)
{
    char buff[12];

    buff[11] = '\0';
    my_strcpy(buff, "Master: 000");
    buff[8] = (store->settings->volume[0] / 100) + '0';
    buff[9] = (store->settings->volume[0] % 100 / 10) + '0';
    buff[10] = (store->settings->volume[0] % 10) + '0';
    sfText_setString(options->master_text, buff);
    my_strcpy(buff, "Sounds: 000");
    buff[8] = (store->settings->volume[1] / 100) + '0';
    buff[9] = (store->settings->volume[1] % 100 / 10) + '0';
    buff[10] = (store->settings->volume[1] % 10) + '0';
    sfText_setString(options->sound_text, buff);
}