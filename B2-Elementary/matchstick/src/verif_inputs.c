/*
** EPITECH PROJECT, 2021
** verif_inputs
** File description:
** file 1
*/

#include "matchstick.h"

int count_matchstick_in_line(const char *str)
{
    int nb_match = 0;

    for (int nb = 0; str[nb]; nb += 1) {
        if (str[nb] == '|')
            nb_match += 1;
    }
    return (nb_match);
}

static int verif_inputs_type_1(my_struct_t *store, int nb, int type)
{
    if (type == 1) {
        if (nb < 1 || nb > store->nb_lines) {
            my_printf("Error: this line is out of range\n");
            return (84);
        }
        store->get_user_line = nb;
    }
    return (0);
}

static int verif_inputs_type_2(my_struct_t *store, int nb, int type)
{
    if (type == 2) {
        if (nb < 1) {
            my_printf("Error: you have to remove at least one match\n");
            return (84);
        }
        if (nb > store->nb_matchstick) {
            my_printf
            ("Error: you cannot remove more than %d matches per turn\n"
            , store->nb_matchstick);
            return (84);
        }
        if (nb > count_matchstick_in_line(store->map[store->get_user_line])) {
            my_printf("Error: not enough matches on this line\n");
            return (84);
        }
        store->get_user_matchstick = nb;
    }
    return (0);
}

int verif_inputs(my_struct_t *store, const char *buff, int type)
{
    int nb = my_getnbr(buff);

    if ((my_nbrlen(nb, 10) != my_strlen(buff) - 1 && nb != 0) || nb < 0
        || my_str_isnum(buff) == 0 || buff[0] == '\n') {
        my_printf("Error: invalid input (positive number expected)\n");
        return (84);
    }
    if (verif_inputs_type_1(store, nb, type) == 84)
        return (84);
    if (verif_inputs_type_2(store, nb, type) == 84)
        return (84);
    return (0);
}