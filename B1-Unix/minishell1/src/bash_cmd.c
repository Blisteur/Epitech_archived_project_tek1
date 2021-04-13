/*
** EPITECH PROJECT, 2021
** bash cmd
** File description:
** file 1
*/

#include "mysh.h"

void my_cd(mysh_t *store)
{
    int tmp = -2;

    if (store->tab_argv[1] == NULL && store->home == NULL)
        tmp = chdir("/");
    if (store->tab_argv[1] == NULL && store->home != NULL)
        tmp = chdir(store->home);
    if (store->tab_argv[1] != NULL && store->tab_argv[2] == NULL)
        tmp = chdir(store->tab_argv[1]);
    if (tmp == -1) {
        my_putstr_error(store->tab_argv[1]);
        my_putstr_error(": ");
        my_putstr_error(strerror(errno));
        my_putstr_error(".\n");
        return;
    }
    if (tmp == -2) {
        my_putstr_error("cd: Too many arguments.\n");
        return;
    }
}

void my_setenv(mysh_t *store)
{
    char *tmp = NULL;

    if (store->tab_argv[1] == NULL) {
        my_env(store);
        return;
    }
    if (store->tab_argv[2] == NULL) {
        setenv_no_arg(store, tmp);
        restart_env(store);
        return;
    }
    if (store->tab_argv[3] == NULL) {
        setenv_with_arg(store, tmp);
        restart_env(store);
        return;
    }
    my_putstr_error("setenv: Too many arguments.\n");
}

void my_unsetenv(mysh_t *store)
{
    if (store->tab_argv[1] == NULL) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return;
    }
    for (int nb = 1; store->tab_argv[nb]; nb += 1) {
        if (my_str_isalpha(store->tab_argv[nb]) == 1) {
            my_putstr_error
            ("setenv: Variable name must contain alphanumeric characters.\n");
            return;
        }
        change_find(store, store->tab_argv[nb]);
    }
}

void my_env(mysh_t *store)
{
    for (int nb = 0; store->env[nb]; nb += 1) {
        my_printf("%s\n", store->env[nb]);
    }
}

void my_exit(mysh_t *store)
{
    store->exit = 1;
}