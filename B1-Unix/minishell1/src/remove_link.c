/*
** EPITECH PROJECT, 2021
** remove link
** File description:
** file 2
*/

#include "mysh.h"

void remove_spe_link(mysh_t *store, env_t *p)
{
    if (p->src == 1)
        free(p->env);
    if (p->previous == NULL) {
        store->link_env->first_env = p->next;
        p->next->previous = NULL;
    }
    if (p->next == NULL) {
        store->link_env->last_env = p->previous;
        p->previous->next = NULL;
    }
    if (p->previous != NULL) {
        p->previous->next = p->next;
    }
    if (p->next != NULL) {
        p->next->previous = p->previous;
    }
    free(p);
    store->link_env->nb_env -= 1;
}