/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** file 1
*/

#include "include/game.h"
#include "include/my.h"

int print_help(void)
{
    int fd;
    struct stat st;
    char buff[help_msg_size + 1];

    buff[help_msg_size] = '\0';
    fd = open("src/help.txt", O_RDONLY);
    if (fd < 0) {
        my_putstr_error("ERROR: help file is missing !\n");
        return (-1);
    }
    stat("src/help.txt", &st);
    if (st.st_size != help_msg_size) {
        my_putstr_error("ERROR: help file modification not authorized !\n");
        return (-1);
    }
    read(fd, buff, help_msg_size);
    my_printf("%s\n", buff);
    close(fd);
    return (0);
}

int verif_texture(void)
{
    struct stat st;
    int error = 0;

    error += stat("src/bg.png", &st);
    error += stat("src/life1.png", &st);
    error += stat("src/life1_d.png", &st);
    error += stat("src/life2.png", &st);
    error += stat("src/life2_d.png", &st);
    error += stat("src/life3.png", &st);
    error += stat("src/life3_d.png", &st);
    error += stat("src/txt1.png", &st);
    error += stat("src/txt1r.png", &st);
    error += stat("src/txt2.png", &st);
    error += stat("src/txt2r.png", &st);
    error += stat("src/txt3.png", &st);
    error += stat("src/txt3r.png", &st);
    error += stat("src/txt4.png", &st);
    error += stat("src/txt4r.png", &st);
    error += stat("src/mt.wav", &st);
    return (error);
}

int error_management(int argc, char **argv)
{
    if (argc > 2)
        return (1);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        if (print_help() == -1)
            return (1);
        return (2);
    }
    if (verif_texture() < 0) {
        my_putstr_error("ERROR: texture file is missing !\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int tmp_error = 0;

    tmp_error = error_management(argc, argv);
    if (tmp_error == 1)
        return (84);
    if (tmp_error == 2)
        return (0);
    game();
    return (0);
}