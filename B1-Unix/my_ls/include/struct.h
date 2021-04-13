/*
** EPITECH PROJECT, 2020
** my_struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

struct specifier
{
    int l;
    int total_l;
    int R;
    int d;
    int lock_d;
    int r;
    int t;
};

typedef struct specifier spe;


struct my_struct
{
    struct specifier *specifier;
    char *link;
    char *name;
    int right;
    char *list_right;
    char *time;
};

typedef struct my_struct my_struct;



#endif /* !MY_STRUCT */