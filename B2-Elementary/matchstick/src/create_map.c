/*
** EPITECH PROJECT, 2021
** create map
** File description:
** file 1
*/

#include "matchstick.h"

int calcul_lenght(my_struct_t *store)
{
    int tmp = 0;

    tmp = ((((store->nb_lines - 1) * 2) + 1) + 2);
    return (tmp);
}

static void delim_map(my_struct_t *store)
{
    for (int nb = 0; nb < calcul_lenght(store); nb += 1) {
        store->map[0][nb] = '*';
    }
    for (int nb = 0; nb < calcul_lenght(store); nb += 1) {
        store->map[store->nb_lines + 1][nb] = '*';
    }
}

static void fill_map(my_struct_t *store)
{
    int tmp = calcul_lenght(store);

    delim_map(store);
    for (int y = 1; y < store->nb_lines + 1; y += 1) {
        store->map[y][0] = '*';
        for (int x = 1; x < tmp; x += 1) {
            store->map[y][x] = ' ';
            if (x <= tmp / 2 + y - 1 && x >= tmp / 2 - y + 1)
                store->map[y][x] = '|';
        }
        store->map[y][tmp - 1] = '*';
    }
}

int create_map(my_struct_t *store)
{
    int lenght = calcul_lenght(store);

    store->map = malloc(sizeof(char *) * (store->nb_lines + 3));
    if (store->map == NULL)
        return (84);
    store->map[store->nb_lines + 2] = NULL;
    for (int nb = 0; nb < (store->nb_lines + 2); nb += 1) {
        store->map[nb] = malloc(sizeof(char) * (lenght + 1));
        if (store->map[nb] == NULL)
            return (84);
        store->map[nb][lenght] = '\0';
    }
    fill_map(store);
    return (0);
}

void destroy_map(my_struct_t *store)
{
    if (store->map == NULL)
        return;
    for (int nb = 0; nb < (store->nb_lines + 2); nb += 1) {
        if (store->map[nb] != NULL)
            free(store->map[nb]);
    }
    free(store->map);
}