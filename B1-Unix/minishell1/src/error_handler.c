/*
** EPITECH PROJECT, 2021
** error handler
** File description:
** file 1
*/

#include "mysh.h"

void error_exit(mysh_t *store)
{
    destroy_struct(store);
    exit(84);
}

void error_handler(mysh_t *store, int argc , char **argv , char **env)
{
    if (argc != 1) {
        my_putstr_error("ERROR: too many arguments !\n");
        error_exit(store);
    }
    if (env == NULL) {
        my_putstr_error("ERROR: empty env !\n");
        error_exit(store);
    }
}