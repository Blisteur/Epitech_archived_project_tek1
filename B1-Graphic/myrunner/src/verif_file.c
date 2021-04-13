/*
** EPITECH PROJECT, 2021
** verif file
** File description:
** file 1
*/

#include "../include/game.h"

int verif_file_exist(int fd)
{
    if (fd == -1) {
        my_putstr_error("ERROR: missing file !\n");
        return (84);
    }
    close(fd);
    return (0);
}

int verif_texture_2(int error)
{
    error +=
        verif_file_exist(open("src/texture/menu_highlight_1.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/menu_highlight_2.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/menu_highlight_3.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/menu_highlight_4.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/menu.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/moon_and_sky.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/star.png", O_RDONLY));
    return (error);
}

int verif_texture(int error)
{
    error += verif_file_exist(open("src/texture/bird_night.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/cactus_type_1.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/cactus_type_2.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/cloud_night.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/dino_jump_night.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/dino_night.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/game_over_hud_day.png", O_RDONLY));
    error +=
        verif_file_exist(open("src/texture/game_over_hud_night.png", O_RDONLY));
    error += verif_file_exist(open("src/texture/ground.png", O_RDONLY));
    error += verif_texture_2(error);
    return (error);
}

int verif_file(void)
{
    int error = 0;

    error += verif_file_exist(open("src/file/settings.txt", O_RDONLY));
    error += verif_file_exist(open("src/file/score.txt", O_RDONLY));
    error += verif_file_exist(open("src/file/dead.wav", O_RDONLY));
    error += verif_file_exist(open("src/file/font.ttf", O_RDONLY));
    error += verif_file_exist(open("src/file/jump.wav", O_RDONLY));
    error += verif_file_exist(open("src/file/music.wav", O_RDONLY));
    error += verif_file_exist(open("src/file/score.wav", O_RDONLY));
    error += verif_texture(error);
    if (error > 0)
        return (84);
    return (0);
}