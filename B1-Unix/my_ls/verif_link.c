/*
** EPITECH PROJECT, 2020
** vrif_link
** File description:
** file 1
*/

#include "include/my_ls.h"

void verif_link(my_struct *store)
{
    for (int nb = 0; store->link[nb] != '\0'; nb += 1) {
        if (store->link[nb] != '/'  && store->link[nb] != '.'
            && store->link[nb + 1] == '\0')
            my_strcat(store->link, "/");
    }
}

int verif_dir(my_struct *store)
{
    struct stat f_stat;
    char tmp[] = "-";
    int error = 0;

    error = stat(store->link, &f_stat);
    if (error == -1) {
        error_management(store);
    }
    type_file(f_stat.st_mode, tmp);
    if (tmp[0] != 'd') {
        my_printf("%s\n", store->link);
        return (1);
    }
    return (0);
}