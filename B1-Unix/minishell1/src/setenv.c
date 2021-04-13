/*
** EPITECH PROJECT, 2021
** setenv
** File description:
** file 1
*/

#include "mysh.h"

int verif_alph(mysh_t *store)
{
    if (my_str_isalpha(store->tab_argv[1]) == 1) {
        my_putstr_error
        ("setenv: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    if (store->tab_argv[2] == NULL)
        return (0);
    if (my_str_isalpha(store->tab_argv[2]) == 1) {
        my_putstr_error
        ("setenv: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

void setenv_no_arg(mysh_t *store, char *tmp)
{
    if (verif_alph(store) == 1)
        return;
    tmp = malloc(sizeof(char) * (my_strlen(store->tab_argv[1]) + 2));
    tmp[my_strlen(store->tab_argv[1]) + 1] = '\0';
    my_strcpy(tmp, store->tab_argv[1]);
    tmp[my_strlen(store->tab_argv[1])] = '=';
    store->link_env->first_env =
        add_link_env(tmp, store, store->link_env->first_env, 1);
}

void setenv_with_arg(mysh_t *store, char *tmp)
{
    if (verif_alph(store) == 1)
            return;
    tmp = malloc(sizeof(char) *
        (my_strlen(store->tab_argv[1]) + my_strlen(store->tab_argv[2]) + 2));
    tmp[my_strlen(store->tab_argv[1])
        + my_strlen(store->tab_argv[2]) + 1] = '\0';
    my_strcpy(tmp, store->tab_argv[1]);
    tmp[my_strlen(store->tab_argv[1])] = '=';
    tmp[my_strlen(store->tab_argv[1]) + 1] = '\0';
    my_strcat(tmp, store->tab_argv[2]);
    store->link_env->first_env =
        add_link_env(tmp, store, store->link_env->first_env, 1);
}