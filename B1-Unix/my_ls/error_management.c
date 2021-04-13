/*
** EPITECH PROJECT, 2020
** error_management
** File description:
** file 1
*/

#include "include/my_ls.h"

void error_management(my_struct *store)
{
    destroy_struct(store);
    my_putstr_error("my_ls: invalid option\n");
    exit(84);
}