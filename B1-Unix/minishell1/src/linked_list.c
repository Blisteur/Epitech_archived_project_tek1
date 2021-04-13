/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** file 1
*/

#include "mysh.h"

path_t *add_link(char *path, mysh_t *store, path_t *p)
{
    path_t *list = malloc(sizeof(path_t));

    list->path = path;
    list->next = p;
    if (p != NULL)
        p->previous = list;
    else
        store->link_path->last_path = list;
    list->previous = NULL;
    p = list;
    store->link_path->nb_path += 1;
    return (list);
}

void remove_link(mysh_t *store, path_t *p)
{
    store->link_path->first_path = p->next;
    store->link_path->first_path->previous = NULL;
    store->link_path->nb_path -= 1;
    free(p);
}

env_t *add_link_env(char *env, mysh_t *store, env_t *p, int src)
{
    env_t *list = malloc(sizeof(env_t));

    list->env = env;
    list->src = src;
    list->next = p;
    if (p != NULL)
        p->previous = list;
    else
        store->link_env->last_env = list;
    list->previous = NULL;
    p = list;
    store->link_env->nb_env += 1;
    return (list);
}

void destroy_linked_list(mysh_t *store)
{
    path_t *tmp1 = NULL;
    env_t *tmp2 = NULL;

    for (int nb = 0; nb < store->link_path->nb_path; nb += 1) {
        tmp1 = store->link_path->first_path->next;
        free(store->link_path->first_path);
        store->link_path->first_path = tmp1;
    }
    for (int nb = 0; nb < store->link_env->nb_env; nb += 1) {
        tmp2 = store->link_env->first_env->next;
        if (store->link_env->first_env->src == 1)
            free(store->link_env->first_env->env);
        free(store->link_env->first_env);
        store->link_env->first_env = tmp2;
    }
}

void change_find(mysh_t *store, char *str)
{
    env_t *tmp = NULL;

    tmp = store->link_env->last_env;
    for (int nb = 0; nb < store->link_env->nb_env; nb += 1) {
        if (compare_string_n(tmp->env, str, my_strlen(str)) == 0) {
            remove_spe_link(store, tmp);
            restart_env(store);
            return;
        }
        tmp = tmp->previous;
    }
}