/*
** EPITECH PROJECT, 2021
** create_map
** File description:
** file 1
*/

#include "my_sokoban.h"

int count_line(char *map)
{
    int nb_line = 0;

    for (int nb = 0; map[nb]; nb += 1) {
        if (map[nb] == '\n')
            nb_line += 1;
    }
    return (nb_line + 1);
}

int malloc_ddmap(my_struct *store, char *buff, size_t buff_size, FILE *fp)
{
    int lenght = 0;

    store->ddmap = malloc(sizeof(char *) * (store->nb_line_map + 1));
    if (store->ddmap == NULL)
        return (84);
    store->ddmap[store->nb_line_map] = NULL;
    for (int nb = 0; nb < store->nb_line_map; nb += 1) {
        lenght = getline(&buff, &buff_size, fp);
        if (buff == NULL)
            return (84);
        if (lenght > store->nb_columns_map)
            store->nb_columns_map = lenght;
        store->ddmap[nb] = buff;
        buff_size = 0;
        buff = NULL;
    }
    return (0);
}

void link_obj(my_struct *store)
{
    for (int nb = 0; nb < store->nb_line_map; nb += 1) {
        for (int subnb = 0; store->ddmap[nb][subnb]; subnb += 1) {
            if (store->ddmap[nb][subnb] == 'X') {
                store->first_obj = add_link(subnb, nb, store, store->first_obj);
                store->ddmap[nb][subnb] = ' ';
            }
        }
    }
    for (int nb = 0; nb < store->nb_line_map; nb += 1) {
        for (int subnb = 0; store->ddmap[nb][subnb]; subnb += 1) {
            if (store->ddmap[nb][subnb] == 'P') {
                store->first_obj = add_link(subnb, nb, store, store->first_obj);
                store->first_obj->c = 'P';
                store->ddmap[nb][subnb] = ' ';
            }
        }
    }
}

int create_map(my_struct *store, const char *map_link)
{
    char *buff = NULL;
    size_t buff_size = 0;
    FILE *fp = NULL;

    store->nb_line_map = count_line(store->map);
    fp = fopen(map_link, "r");
    if (fp == NULL)
        return (84);
    if (malloc_ddmap(store, buff, buff_size, fp) == 84)
        return (84);
    link_obj(store);
    fclose(fp);
    return (0);
}