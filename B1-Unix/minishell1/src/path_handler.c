/*
** EPITECH PROJECT, 2021
** pathhandler
** File description:
** file 1
*/

#include "mysh.h"

char *make_full_path(mysh_t *store, path_t *tmp_path)
{
    int len_path = my_strlen(tmp_path->path);
    int len_tab = my_strlen(store->tab_argv[0]);
    char *concat_path = malloc(sizeof(char) * (len_path + len_tab + 2));
    int nb = 0;

    concat_path[(len_path + len_tab + 1)] = '\0';
    for (nb = 0; tmp_path->path[nb]; nb += 1)
        concat_path[nb] = tmp_path->path[nb];
    concat_path[nb] = '/';
    nb += 1;
    for (int subnb = 0; store->tab_argv[0][subnb]; nb += 1, subnb += 1)
        concat_path[nb] = store->tab_argv[0][subnb];
    return (concat_path);
}

void full_path(mysh_t *store)
{
    if (access(store->tab_argv[0], F_OK) == 0) {
        execve(store->tab_argv[0], store->tab_argv, store->env);
        return;
    }
    my_putstr_error(store->tab_argv[0]);
    my_putstr_error(": Command not found.\n");
}

void test_path(mysh_t *store)
{
    path_t *tmp_path = store->link_path->first_path;
    char *concat_path = NULL;

    if (store->tab_argv[0][0] == '.' || store->tab_argv[0][0] == '/') {
        full_path(store);
        return;
    }
    for (int nb = 0; nb < store->link_path->nb_path; nb += 1) {
        concat_path = make_full_path(store, tmp_path);
        if (access(concat_path, F_OK) == 0) {
            execve(concat_path, store->tab_argv, store->env);
            free(concat_path);
            break;
        }
        free(concat_path);
        tmp_path = tmp_path->next;
    }
    my_putstr_error(store->tab_argv[0]);
    my_putstr_error(": Command not found.\n");
}