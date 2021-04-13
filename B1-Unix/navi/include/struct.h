/*
** EPITECH PROJECT, 2020
** struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

struct my_struct
{
    int usr;
    int game_stade;
    int attack_statue;
    char **ally_map;
    char **enemy_map;
    int enemy_pid;
    int lock_enemy_pid_ok;
    int enemy_attack_let;
    int enemy_attack_nb;
};
typedef struct my_struct my_struct;

struct verif_map_struct
{
    int boat2;
    int boat3;
    int boat4;
    int boat5;
    int error;
    int x_min;
    int y_min;
    int x_max;
    int y_max;
};
typedef struct verif_map_struct verif_map_struct;

#endif /* !MY_STRUCT */