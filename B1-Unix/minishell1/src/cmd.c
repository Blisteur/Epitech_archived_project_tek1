/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** file
*/

#include "mysh.h"

void verif_child(mysh_t *store, int stat)
{
    if (WIFEXITED(stat) == 1 && store->mode_tty == 0)
        store->exit_statue = WEXITSTATUS(stat);
    if (WIFSIGNALED(stat) == 1) {
        if (WCOREDUMP(stat) == 128) {
            my_putstr_error("Segmentation fault (core dumped)\n");
        } else if (WCOREDUMP(stat) > 0)
            my_putstr_error("Segmentation fault\n");
    }
}

void cmd_test(mysh_t *store)
{
    int stat = 0;

    for (int nb = 0; store->ptr[nb]; nb += 1) {
        if (compare_string(store->tab_argv[0], store->name_ptr[nb]) == 0) {
            store->ptr[nb](store);
            return;
        }
    }
    if (fork() == 0) {
        test_path(store);
        my_exit(store);
    } else {
        wait(&stat);
        verif_child(store, stat);
    }
}