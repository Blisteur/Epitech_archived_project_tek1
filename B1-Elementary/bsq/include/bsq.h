/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** .h
*/

#ifndef BSQ
#define BSQ

#define error_code (84)

typedef struct my_struct my_struct;

void init_struct(my_struct *store);
void delete_struct(my_struct *store);
int error_management(int argc, char **argv, my_struct *store, struct stat info);
void verif_execp(my_struct *store);
void print_bsq(my_struct *store);

#endif /* !BSQ */
