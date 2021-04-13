/*
** EPITECH PROJECT, 2021
** make map
** File description:
** file 1
*/

#include "../include/game.h"

void make_mob_with_map(my_game *store)
{
    for (int nb = 0; store->map[nb] != '2'; nb += 1) {
        if (store->map[nb] == '1') {
            store->mob_list_first
            = add_link_mob(store, store->mob_list_first, random_mob(nb));
            store->mob_list_first->pose.x = 1920 + nb * 700;
        }
    }
    make_mob(store);
}

void make_mob_without_map(my_game *store)
{
    int random = 3;

    for (int nb = 0; nb < 550; nb += 1, random *= random) {
        if (random_mob_spawn(random) == 1) {
            store->mob_list_first
            = add_link_mob(store, store->mob_list_first, random_mob(nb));
            store->mob_list_first->pose.x = 1920 + nb * 800;
        }
    }
    make_mob(store);
}

void make_map_file(my_game *store, char *map_link)
{
    int fd = open(map_link, O_RDONLY);
    char *buff = malloc(sizeof(char) * 2);
    int nb = 0;

    buff[1] = '\0';
    while (read(fd, buff, 1) != 0) {
        nb += 1;
    }
    free(buff);
    close(fd);
    buff = malloc(sizeof(char) * nb + 1);
    buff[nb] = '\0';
    fd = open(map_link, O_RDONLY);
    read(fd, buff, nb);
    store->map = malloc(sizeof(char) * nb + 1);
    store->map[nb] = '\0';
    my_strcpy(store->map, buff);
    free(buff);
    close(fd);
    make_mob_with_map(store);
}

void make_map(my_game *store, char *map_link)
{
    if (map_link[0] != '-') {
        make_map_file(store, map_link);
        return;
    }
    store->map = malloc(sizeof(char) * 2);
    store->map[0] = 'i';
    store->map[1] = '\0';
    make_mob_without_map(store);
}

void remake_map(my_game *store)
{
    if (store->map[0] == 'i')
        make_mob_without_map(store);
    else
        make_mob_with_map(store);

}