/*
** EPITECH PROJECT, 2020
** my_param_to_list
** File description:
** task01
*/

#include "include/mylist.h"

void my_print_list(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != '\0') {
        my_put_str(tmp->data);
        tmp = tmp->next;
    }
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *link;
    linked_list_t *previous = '\0';

    for (int count = 0; count < ac; count += 1) {
        link = malloc(sizeof(linked_list_t));
        link->data = av[count];
        if (previous != '\0')
            previous->next = link;
        previous = link;
    }
}