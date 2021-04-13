/*
** EPITECH PROJECT, 2020
** struct
** File description:
** file 1
*/

#include "include/my_ls.h"

void init_struct(my_struct *store)
{
    store->specifier->l = 0;
    store->specifier->R = 0;
    store->specifier->d = 0;
    store->specifier->r = 0;
    store->specifier->t = 0;
    store->specifier->total_l = 0;
    store->link = ".";
    store->right = 0;
    store->specifier->lock_d = 0;
}

void destroy_struct(my_struct *store)
{
    free(store->specifier);
    free(store->name);
    free(store);
}