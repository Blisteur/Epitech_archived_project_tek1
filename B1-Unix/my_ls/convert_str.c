/*
** EPITECH PROJECT, 2020
** convert_str
** File description:
** file 1
*/

#include "include/my_ls.h"

void convert_str(my_struct *store, char *str)
{
    if (store->name != NULL)
        free(store->name);
    store->name = malloc(sizeof(char) *
                (my_strlen(str) + my_strlen(store->link) + 1));
    store->name[my_strlen(str) + my_strlen(store->link)] = '\0';
    my_strcpy(store->name, store->link);
    my_strcat(store->name, str);
}