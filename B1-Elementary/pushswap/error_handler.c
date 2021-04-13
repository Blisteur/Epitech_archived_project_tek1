/*
** EPITECH PROJECT, 2020
** error_handler
** File description:
** file 1
*/

#include "include/push_swap.h"

void help(void)
{
    my_printf("USAGE:\n./push_swap (lists of numbers)\n");
}

int is_number(char *str_nb)
{
    int sign = 0;

    for (int count = 0; str_nb[count] != '\0'; count += 1) {
        if (str_nb[count] == '-')
            sign += 1;
        if ((str_nb[count] < '0' || str_nb[count] > '9')
            && str_nb[count] != '-')
            return (84);
        if (sign > 1)
            return (84);
    }
    return (0);
}

int error_handler(int argc, char **argv)
{
    if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0')) {
        help();
        return (84);
    }
    for (int nb = 1; nb < argc; nb += 1) {
        if (is_number(argv[nb]) == 84) {
            my_putstr_error("ERROR: only numbers are accepted !\n");
            my_putstr_error("USE: \"./push_swap -h\" for more information\n");
            return (84);
        }
    }
    return (0);

}