/*
** EPITECH PROJECT, 2021
** mysy
** File description:
** file 1
*/

#ifndef MY_SH
#define MY_SH

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#include "my.h"
#include "struct.h"

mysh_t *create_struct(void);
int destroy_struct(mysh_t *store);
void error_handler(mysh_t *store, int argc , char **argv , char **env);
void cmd_test(mysh_t *store);
void my_cd(mysh_t *store);
void my_setenv(mysh_t *store);
void my_unsetenv(mysh_t *store);
void my_env(mysh_t *store);
void my_exit(mysh_t *store);
void get_in(mysh_t *store);
void get_env(mysh_t *store);
void signal_handler(int code);
path_t *add_link(char *path, mysh_t *store, path_t *p);
void remove_link(mysh_t *store, path_t *p);
env_t *add_link_env(char *env, mysh_t *store, env_t *p, int src);
void destroy_linked_list(mysh_t *store);
void test_path(mysh_t *store);
void get_env(mysh_t *store);
int compare_string(char *str1, char *str2);
int compare_string_n(char *str1, char *str2, int n);
void change_find(mysh_t *store, char *str);
void setenv_no_arg(mysh_t *store, char *tmp);
void setenv_with_arg(mysh_t *store, char *tmp);
int verif_alph(mysh_t *store);
void remove_spe_link(mysh_t *store, env_t *p);
void restart_env(mysh_t *store);

#endif /* !MY_SH */