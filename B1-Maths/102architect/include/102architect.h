/*
** EPITECH PROJECT, 2020
** 102architect
** File description:
** .h
*/

#ifndef ARCHITECT
#define ARCHITECT

typedef struct my_struct my_struct;

void init_struct(char **argv, my_struct *store);
void destroy_struct(my_struct *store);
void calculate_translate(my_struct *store, float i, float j);
void calculate_scale(my_struct *store, float m, float n);
void calculate_rotation(my_struct *store, float d);
void calculate_reflection(my_struct *store, float d);
void error_management(int argc, char **argv);
void help(void);
void calculate_matrix(my_struct *store, int i);
void calculate_translate(my_struct *store, float i, float j);
void calculate_scale(my_struct *store, float m, float n);
void calculate_rotation(my_struct *store, float d);
void calculate_reflection(my_struct *store, float d);

#endif /* !ARCHITECT */