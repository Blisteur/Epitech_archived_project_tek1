/*
** EPITECH PROJECT, 2021
** error_handler
** File description:
** file 1
*/

#include "matchstick.h"

static int verif_line(my_struct_t *store, const char *str)
{
    if (my_str_isnum(str) == 0)
        return (84);
    store->nb_lines = my_getnbr(str);
    if (store->nb_lines <= 1 || store->nb_lines >= 100)
        return (84);
    return (0);
}

static int verif_matchstick(my_struct_t *store, const char *str)
{
    if (my_str_isnum(str) == 0)
        return (84);
    store->nb_matchstick = my_getnbr(str);
    if (store->nb_matchstick <= 0)
        return (84);
    return (0);
}

int error_handler(my_struct_t *store, const int argc
                , const char * const * argv)
{
    if (store == NULL) {
        my_putstr_error("ERROR: malloc NULL !\n");
        return (84);
    }
    if (argc != 3) {
        my_putstr_error("ERROR: too few or too many argument !\n");
        return (84);
    }
    if (verif_line(store, argv[1]) == 84) {
        my_putstr_error("ERROR: line only contain numbers and (1<N<100) !\n");
        return (84);
    }
    if (verif_matchstick(store, argv[2]) == 84) {
        my_putstr_error("ERROR: matchstick only contain numbers and (N>0) !\n");
        return (84);
    }
    return (0);
}