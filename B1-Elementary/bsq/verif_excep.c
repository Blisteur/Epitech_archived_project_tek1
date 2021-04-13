/*
** EPITECH PROJECT, 2020
** verif_except
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/bsq.h"

void verif_execp(my_struct *store)
{
    for (int nb = 0; store->buff[nb] != '\0'; nb += 1) {
        if (store->buff[nb] == '.') {
            store->buff[nb] = 'x';
            break;
        }
    }
    write(1, store->buff, store->buff_size);
}