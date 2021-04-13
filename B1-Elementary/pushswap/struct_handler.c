/*
** EPITECH PROJECT, 2020
** struct
** File description:
** file 1
*/

#include "include/push_swap.h"

my_struct *init_struct(void)
{
    my_struct *store = malloc(sizeof(my_struct));

    store->nb_link_list_a = 0;
    store->nb_link_list_b = 0;
    store->list_a_first = NULL;
    store->list_b_first = NULL;
    store->list_a_last = NULL;
    store->list_b_last = NULL;
    return (store);
}

linked_list *add_link(int nb, my_struct *store, linked_list *p, char lst)
{
    linked_list *list = malloc(sizeof(linked_list));

    list->number = nb;
    list->next = p;
    if (p != NULL)
        p->previous = list;
    list->previous = NULL;
    p = list;
    if (lst == 'a')
        store->nb_link_list_a += 1;
    else
        store->nb_link_list_b += 1;
    return (list);
}

void remove_link(my_struct *store, linked_list *p, char lst)
{
    if (lst == 'a') {
        store->list_a_first = p->next;
        store->nb_link_list_a -= 1;
    }
    else {
        store->list_b_first = p->next;
        store->nb_link_list_b -= 1;
    }
    free(p);
}

void my_rev_list(my_struct *store, linked_list *list)
{
    linked_list *tmp;

    for (int nb = 0; nb < store->nb_link_list_a; nb += 1) {
        if (list->next == NULL)
            store->list_a_first = list;
        if (list->previous == NULL)
            store->list_a_last = list;
        tmp = list->previous;
        list->previous = list->next;
        list->next = tmp;
        list = list->previous;
    }
}

void destroy_struct(my_struct *store)
{
    linked_list *tmp;

    for (int nb = 0; nb < store->nb_link_list_a; nb += 1) {
        tmp = store->list_a_first->next;
        free(store->list_a_first);
        store->list_a_first = tmp;
    }
    for (int nb = 0; nb < store->nb_link_list_b; nb += 1) {
        tmp = store->list_b_first->next;
        free(store->list_b_first);
        store->list_b_first = tmp;
    }
    free(store);
}