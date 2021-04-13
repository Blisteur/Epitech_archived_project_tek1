/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** .h
*/

#ifndef MY_LS
#define MY_LS

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"
#include "struct.h"

typedef struct specifier spe;
typedef struct my_struct my_struct;

void init_struct(my_struct *store);
void destroy_struct(my_struct *store);
void error_management(my_struct *store);
void convert_octal(my_struct *store, unsigned int nb);
void print_right(my_struct *store, unsigned int nb);
void convert_time(char *str, my_struct *store);
void convert_str(my_struct *store, char *str);
void verif_link(my_struct *store);
void type_file(unsigned int type, char *str);
int verif_dir(my_struct *store);
void print_with_l(my_struct *store, char *str);

#endif /* !MY_LS */