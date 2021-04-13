/*
** EPITECH PROJECT, 2020
** my_struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

struct my_struct
{
    float x;
    float y;
    float final_x;
    float final_y;
    float tmp_x;
    float tmp_y;
    float tmp_d;
    float **tab;
    float **tmp_tab;
    float *matrix_tmp;
    int lock;
};

typedef struct my_struct my_struct;


#endif /* !MY_STRUCT */
