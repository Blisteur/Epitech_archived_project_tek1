/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "mysh.h"

int main(int argc , char **argv , char **env)
{
    mysh_t *store = create_struct();

    error_handler(store, argc, argv, env);
    store->env = env;
    get_env(store);
    store->env = NULL;
    restart_env(store);
    signal(SIGINT, signal_handler);
    while (store->exit == 0) {
        if (store->mode_tty == 1)
            my_printf("$> ");
        get_in(store);
    }
    return (destroy_struct(store));
}