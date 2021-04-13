/*
** EPITECH PROJECT, 2021
** struct .h
** File description:
** .h
*/

#ifndef STRUCT_MYSH
#define STRUCT_MYSH

typedef struct path_s
{
    char *path;
    struct path_s *next;
    struct path_s *previous;
}path_t;

typedef struct linked_list_s
{
    int nb_path;
    path_t *first_path;
    path_t *last_path;
}linked_list_t;

typedef struct env_s
{
    char *env;
    int src;
    struct env_s *next;
    struct env_s *previous;
}env_t;

typedef struct env_list_s
{
    int nb_env;
    env_t *first_env;
    env_t *last_env;
}env_list_t;

typedef struct mysh_s
{
    int nb_word;
    int exit;
    int mode_tty;
    char **tab_argv;
    char **env;
    char *home;
    char *tmp_path;
    int exit_statue;
    linked_list_t *link_path;
    env_list_t *link_env;
    char *name_ptr[6];
    void (*ptr[6])(struct mysh_s *store);
}mysh_t;

#endif /* !STRUCT_MYSH */