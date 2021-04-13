/*
** EPITECH PROJECT, 2021
** make score
** File description:
** file 1
*/

#include "../include/game.h"

void get_high_score(my_game *store)
{
    int fd = open("src/file/score.txt", O_RDONLY);
    char buff[5];

    read(fd, buff, 5);
    for (int nb = 0; nb < 5; nb += 1) {
        if (buff[nb] <= '9' && buff[nb] >= '0')
            store->score->text[nb + 4] = buff[nb];
        else
            store->score->text[nb + 4] = '0';
    }
    close(fd);
}

void init_score(my_game *store)
{
    store->score = malloc(sizeof(score_t));
    store->score->font = sfFont_createFromFile("src/file/font.ttf");
    store->score->hi_text = sfText_create();
    store->score->text = malloc(sizeof(char) * 17);
    store->score->text[16] = '\0';
    my_strcpy(store->score->text, "HI  00000  00000");
    get_high_score(store);
    store->score->pose.x = 1520;
    store->score->pose.y = 100;
    store->score->color = sfColor_fromRGB(192, 192, 192);
    store->score->nb_co_score = 0;
    sfText_setFont(store->score->hi_text, store->score->font);
    sfText_setCharacterSize(store->score->hi_text, 40);
    sfText_setString(store->score->hi_text, store->score->text);
    sfText_setColor(store->score->hi_text, store->score->color);
    sfText_setPosition(store->score->hi_text, store->score->pose);
}

void make_high_score(my_game *store)
{
    int fd = open("src/file/score.txt", O_RDWR, O_CREAT);
    char tmp1[] = "00000";
    char tmp2[] = "00000";

    my_strcpy(tmp1, store->score->text + 11);
    my_strncpy(tmp2, store->score->text + 4, 5);
    if (my_getnbr(tmp1) > my_getnbr(tmp2)) {
        score_actu(store, 4);
        write(fd, tmp1, 5);
    }
    close(fd);
}

void score_actu(my_game *store, int mode)
{
    int tmp = my_nbrlen(store->score->nb_co_score, 10);

    score_music(store);
    if (mode == 11)
        store->score->nb_co_score += 1;
    if (tmp >= 1)
        store->score->text[mode + 4] = (store->score->nb_co_score % 10) + '0';
    if (tmp >= 2)
        store->score->text[mode + 3] =
        (store->score->nb_co_score % 100 / 10) + '0';
    if (tmp >= 3)
        store->score->text[mode + 2] =
        (store->score->nb_co_score % 1000 / 100) + '0';
    if (tmp >= 4)
        store->score->text[mode + 1] =
        (store->score->nb_co_score % 10000 / 1000) + '0';
    if (tmp >= 5)
        store->score->text[mode] =
        (store->score->nb_co_score % 100000 / 10000) + '0';
    sfText_setString(store->score->hi_text, store->score->text);
}

void destroy_score(my_game *store)
{
    free(store->score->text);
    sfFont_destroy(store->score->font);
    sfText_destroy(store->score->hi_text);
    free(store->score);
}