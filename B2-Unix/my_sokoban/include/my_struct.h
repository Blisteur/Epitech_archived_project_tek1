/*
** EPITECH PROJECT, 2021
** my_struct
** File description:
** .h
*/

#ifndef SOKOBAN_STRUCT
#define SOKOBAN_STRUCT

typedef struct my_obj
{
    int x;
    int y;
    char c;
    int origin_x;
    int origin_y;
    struct my_obj *next;
    struct my_obj *previous;
}my_obj;

typedef struct my_struct
{
    char *map;
    char **ddmap;
    int nb_line_map;
    int loop_stop;
    int nb_columns_map;
    my_obj *first_obj;
    my_obj *last_obj;
    int nbr_obj;
}my_struct;

#endif /* !SOKOBAN_STRUCT */