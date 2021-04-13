/*
** EPITECH PROJECT, 2020
** swap
** File description:
** file 1
*/

#include "include/push_swap.h"

void rotate_f_to_l(linked_list *list_x, my_struct *store, char lst)
{
    if ((lst == 'a' && store->nb_link_list_a < 2)
    || (lst == 'b' && store->nb_link_list_b < 2))
        return;
    if (lst == 'a') {
        store->list_a_first = list_x->next;
        list_x->next->previous = NULL;
        list_x->next = NULL;
        store->list_a_last->next = list_x;
        list_x->previous = store->list_a_last;
        store->list_a_last = list_x;
    } else {
        store->list_b_first = list_x->next;
        list_x->next->previous = NULL;
        list_x->next = NULL;
        store->list_b_last->next = list_x;
        list_x->previous = store->list_b_last;
        store->list_b_last = list_x;
    }
}

void rotate_l_to_f(linked_list *list_x, my_struct *store, char lst)
{
    if ((lst == 'a' && store->nb_link_list_a < 2)
    || (lst == 'b' && store->nb_link_list_b < 2))
        return;
    if (lst == 'a') {
        store->list_a_last = list_x->previous;
        list_x->next = store->list_a_first;
        store->list_a_first = list_x;
        list_x->next->previous = list_x;
        list_x->previous->next = NULL;
        list_x->previous = NULL;
    } else {
        store->list_b_last = list_x->previous;
        list_x->next = store->list_b_first;
        store->list_b_first = list_x;
        list_x->next->previous = list_x;
        list_x->previous->next = NULL;
        list_x->previous = NULL;
    }
}

void count_push(my_struct *store, char lst)
{
    if (lst == 'a') {
        store->nb_link_list_a -= 1;
        store->nb_link_list_b += 1;
    }
    else {
        store->nb_link_list_b -= 1;
        store->nb_link_list_a += 1;
    }
}

void push(linked_list *list_x, my_struct *store, char lst)
{
    if (lst == 'a' && store->nb_link_list_a > 0) {
        store->list_a_first = list_x->next;
        store->list_a_first->previous = NULL;
        list_x->next = store->list_b_first;
        store->list_b_first = list_x;
        if (list_x->next != NULL)
            list_x->next->previous = list_x;
        else
            store->list_b_last = list_x;
        count_push(store, 'a');
    }
    if (lst == 'b' && store->nb_link_list_b != 0) {
        store->list_b_first = list_x->next;
        if (list_x->next != NULL)
            list_x->next->previous = NULL;
        list_x->next = store->list_a_first;
        store->list_a_first = list_x;
        list_x->next->previous = list_x;
        count_push(store, 'b');
    }
}

void swap(linked_list *list, my_struct *store, char lst)
{
    linked_list *tmp_next;

    if ((lst == 'a' && store->nb_link_list_a < 2)
    || (lst == 'b' && store->nb_link_list_b < 2))
        return;
    tmp_next = list->next;
    if (tmp_next->next != NULL)
        tmp_next->next->previous = list;
    list->previous = tmp_next;
    list->next = tmp_next->next;
    tmp_next->next = list;
    tmp_next->previous = NULL;
    if (lst == 'a')
        store->list_a_first = tmp_next;
    else
        store->list_b_first = tmp_next;
}