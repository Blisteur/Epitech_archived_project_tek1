/*
** EPITECH PROJECT, 2020
** main
** File description:
** file 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/102architect.h"
#include "include/struct.h"

void calculate(int argc, char **argv, my_struct *store)
{
    store->x = atof(argv[1]);
    store->y = atof(argv[2]);
    store->final_x = store->x;
    store->final_y = store->y;
    for (int nb = 3; nb < argc; nb += 1) {
        if (argv[nb][1] == 't')
            calculate_translate(store, atof(argv[nb + 1]), atof(argv[nb + 2]));
        if (argv[nb][1] == 'z')
            calculate_scale(store, atof(argv[nb + 1]), atof(argv[nb + 2]));
        if (argv[nb][1] == 'r')
            calculate_rotation(store, atof(argv[nb + 1]));
        if (argv[nb][1] == 's')
            calculate_reflection(store, atof(argv[nb + 1]));
        if (store->lock == 1 && nb == 3)
            calculate_matrix(store, 1);
        if (store->lock == 1 && nb != 3)
            calculate_matrix(store, 0);
    }
    for (int nb = 0; nb < 3; nb += 1)
            printf("%.2f %.2f %.2f\n", store->tab[0][nb], store->tab[1][nb], store->tab[2][nb]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", store->x, store->y, store->final_x, store->final_y);
}

void help(void)
{
    int fd = 0;
    char buff[459];

    fd = open("help.txt", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "ERROR: missing help file !\n");
        exit(84);
    }
    read(fd, buff, 458);
    printf("%s\n", buff);
    exit(0);

}

int main(int argc, char **argv)
{
    my_struct *store;

    error_management(argc, argv);
    store = malloc(sizeof(my_struct));
    init_struct(argv, store);
    calculate(argc, argv, store);
    destroy_struct(store);
    return (0);
}