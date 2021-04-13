/*
** EPITECH PROJECT, 2021
** env handler
** File description:
** file 1
*/

#include "mysh.h"

void restart_env(mysh_t *store)
{
    env_t *tmp = NULL;

    if (store->env != NULL)
        free(store->env);
    store->env = malloc(sizeof(char *) * (store->link_env->nb_env + 1));
    store->env[store->link_env->nb_env] = NULL;
    tmp = store->link_env->last_env;
    for (int nb = 0; nb < store->link_env->nb_env; nb += 1) {
        store->env[nb] = tmp->env;
        tmp = tmp->previous;
    }
}

void cpy_env(mysh_t *store)
{
    for (int nb = 0; store->env[nb]; nb += 1) {
        store->link_env->first_env
            = add_link_env(store->env[nb], store
            , store->link_env->first_env, 0);
    }
}

char *cpy_env_var(char *env_str)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(env_str) + 1));

    tmp[my_strlen(env_str)] = '\0';
    return (my_strcpy(tmp, env_str));
}

void get_home_and_path(mysh_t *store, char **tmp)
{
    for (int nb = 0; store->env[nb]; nb += 1) {
        if (compare_string_n(store->env[nb], "HOME", 4) == 0)
            store->home = cpy_env_var(store->env[nb]);
        if (compare_string_n(store->env[nb], "PATH", 4) == 0)
            *tmp = cpy_env_var(store->env[nb]);
    }
}

void get_env(mysh_t *store)
{
    char *tmp = NULL;
    char *tmp_cpy = NULL;

    cpy_env(store);
    get_home_and_path(store, &tmp);
    if (store->home != NULL) {
        tmp_cpy = strtok(store->home, "=");
        store->home = strtok(NULL, "");
        free(tmp_cpy);
    }
    if (tmp != NULL) {
        store->tmp_path = strtok(tmp, "=");
        store->link_path->first_path
        = add_link(strtok(NULL, ":"), store, store->link_path->first_path);
        while (store->link_path->first_path->path != NULL) {
            store->link_path->first_path
            = add_link(strtok(NULL, ":"), store, store->link_path->first_path);
        }
        remove_link(store, store->link_path->first_path);
    }
}