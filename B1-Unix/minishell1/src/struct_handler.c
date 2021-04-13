/*
** EPITECH PROJECT, 2021
** struct_handler
** File description:
** file 1
*/

#include "mysh.h"

void init_list(mysh_t *store)
{
    store->link_path->first_path = NULL;
    store->link_path->last_path = NULL;
    store->link_path->nb_path = 0;
    store->link_env->first_env = NULL;
    store->link_env->last_env = NULL;
    store->link_env->nb_env = 0;
}

void init_ptr(mysh_t *store)
{
    store->ptr[0] = my_cd;
    store->ptr[1] = my_setenv;
    store->ptr[2] = my_unsetenv;
    store->ptr[3] = my_env;
    store->ptr[4] = my_exit;
    store->ptr[5] = NULL;
    store->name_ptr[0] = "cd";
    store->name_ptr[1] = "setenv";
    store->name_ptr[2] = "unsetenv";
    store->name_ptr[3] = "env";
    store->name_ptr[4] = "exit";
    store->name_ptr[5] = NULL;
}

void verif_malloc_struct(mysh_t *store)
{
    store->link_path = malloc(sizeof(linked_list_t));
    if (store->link_path == NULL) {
        free(store);
        my_putstr_error("ERROR: MALLOC NULL !");
        exit(84);
    }
    store->link_env = malloc(sizeof(env_t));
    if (store->link_env == NULL) {
        free(store->link_path);
        free(store);
        my_putstr_error("ERROR: MALLOC NULL !");
        exit(84);
    }
}

mysh_t *create_struct(void)
{
    mysh_t *store = malloc(sizeof(mysh_t));

    if (store == NULL) {
        my_putstr_error("ERROR: MALLOC NULL !");
        exit(84);
    }
    verif_malloc_struct(store);
    store->exit = 0;
    store->exit_statue = 0;
    store->nb_word = 0;
    store->tab_argv = NULL;
    store->env = NULL;
    store->home = NULL;
    store->tmp_path = NULL;
    init_list(store);
    store->mode_tty = isatty(0);
    init_ptr(store);
    return (store);
}

int destroy_struct(mysh_t *store)
{
    int exit_code = store->exit_statue;

    destroy_linked_list(store);
    free(store->env);
    if (store->tmp_path != NULL)
        free(store->tmp_path);
    free(store->link_env);
    free(store->link_path);
    free(store);
    return (exit_code);
}