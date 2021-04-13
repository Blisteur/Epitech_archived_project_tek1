/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** file 1
*/

#include "include/push_swap.h"

void debug_print(my_struct *store)
{
    linked_list *tmp;

    tmp = store->list_a_first;
    for (int nb = 0; nb < store->nb_link_list_a; nb += 1) {
        my_printf("list a: %d : %p :", tmp->number, tmp);
        my_printf("  %p", tmp->previous);
        my_printf("  %p\n", tmp->next);
        tmp = tmp->next;
    }
    tmp = store->list_b_first;
    for (int nb = 0; nb < store->nb_link_list_b; nb += 1) {
        my_printf("list b: %d : %p :", tmp->number, tmp);
        my_printf("  %p", tmp->previous);
        my_printf("  %p\n", tmp->next);
        tmp = tmp->next;
    }
}

void print_pushswap(my_struct *store, char *value, int nb)
{
    if (store->count_pushswap != 0)
        write(1, " ", 1);
    store->count_pushswap += 1;
    write(1, value, nb);
}

void sort_lb_adv(my_struct *store, int count)
{
    linked_list *tmp = store->list_b_last->previous;

    while (tmp->number < store->list_b_first->number) {
        count += 1;
        tmp = tmp->previous;
    }
    if ((count + 2) == store->nb_link_list_b) {
        swap(store->list_b_first, store, 'b');
        print_pushswap(store, "sb", 2);
        return;
    }
    for (int nb = 0; nb < count; nb += 1) {
        rotate_l_to_f(store->list_b_last, store, 'b');
        swap(store->list_b_first, store, 'b');
        print_pushswap(store, "rrb sb", 6);
    }
    for (int nb = 0; nb < (count + 1); nb += 1) {
        rotate_f_to_l(store->list_b_first, store, 'b');
        print_pushswap(store, "rb", 2);
    }
}

void sort_lb(my_struct *store)
{
    if (store->list_b_first->next->number <= store->list_b_first->number)
        return;
    if (store->list_b_first->next->number > store->list_b_first->number) {
        if (store->list_b_last->number >= store->list_b_first->number) {
            rotate_f_to_l(store->list_b_first, store, 'b');
            print_pushswap(store, "rb", 2);
        } else
            sort_lb_adv(store, 1);
    }
}

void sort(my_struct *store)
{
    while (store->nb_link_list_a != 1) {
        debug_print(store);
        if (store->list_a_first->next->number >= store->list_a_first->number) {
            push(store->list_a_first, store, 'a');
            print_pushswap(store, "pb", 2);
        }
        else {
            swap(store->list_a_first, store, 'a');
            push(store->list_a_first, store, 'a');
            print_pushswap(store, "sa pb", 5);
        }
        if (store->nb_link_list_b > 1)
            sort_lb(store);
    }
    while (store->nb_link_list_b != 0) {
        push(store->list_b_first, store, 'b');
        print_pushswap(store, "pa", 2);
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    my_struct *store;

    if (error_handler(argc, argv) == 84)
        return (84);
    if (excep_handler(argc, argv) == 1)
        return (0);
    store = init_struct();
    for (int nb = 1; nb < argc; nb += 1) {
        store->list_a_first = add_link(my_getnbr(argv[nb])
                                , store, store->list_a_first, 'a');
    }
    my_rev_list(store, store->list_a_first);
    sort(store);
    destroy_struct(store);
    return (0);
}