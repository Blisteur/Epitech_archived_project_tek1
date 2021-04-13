/*
** EPITECH PROJECT, 2021
** get_all_cmd
** File description:
** file 1
*/

#include "mysh.h"

void get_word(mysh_t *store, char *str)
{
    int lock = 0;

    for (int nb = 0; str[nb]; nb += 1) {
        if (str[nb] == '\t')
            str[nb] = ' ';
        if (lock == 0 && str[nb] != ' ')
            lock += 1;
        if (lock == 1 && (str[nb] == ' ' || str[nb] == '\n')
            && str[nb- 1] != ' ')
            store->nb_word += 1;
    }
}

void init_tab_argv(mysh_t *store, char *str)
{
    store->tab_argv[0] = strtok(str, " , \n");
    for (int nb = 1; nb < store->nb_word; nb += 1) {
        store->tab_argv[nb] = strtok(NULL, " , \n");
    }
}

void get_cmd(mysh_t *store, char *buff)
{
    get_word(store, buff);
    store->tab_argv = malloc(sizeof(char *) * (store->nb_word + 1));
    if (store->tab_argv == NULL)
        return;
    store->tab_argv[store->nb_word] = NULL;
    init_tab_argv(store, buff);
    cmd_test(store);
    free(store->tab_argv);
}

void get_in(mysh_t *store)
{
    char *buff = NULL;
    size_t buff_size = 0;
    int length = 0;

    length = getline(&buff, &buff_size, stdin);
    if (length == -1) {
        if (store->mode_tty == 1)
            write(1, "exit\n", 5);
        my_strcpy(buff, "exit");
    }
    if (buff[0] != '\n' && length != 0)
        get_cmd(store, buff);
    free(buff);
}