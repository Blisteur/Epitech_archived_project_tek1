/*
** EPITECH PROJECT, 2020
** main
** File description:
** file 1
*/


#include "include/my_ls.h"

void print_with_l(my_struct *store, char *str)
{
    struct stat f_stat;
    struct passwd *f_passwd;
    struct group *f_group;

    convert_str(store, str);
    if (store->link[0] == '.' && store->link[1] == '\0')
        lstat(str, &f_stat);
    else
        lstat(store->name, &f_stat);
    f_passwd = getpwuid(f_stat.st_uid);
    f_group = getgrgid(f_stat.st_gid);
    convert_time(ctime(&f_stat.st_ctime), store);
    print_right(store, f_stat.st_mode);
    my_printf("%s. ", store->list_right);
    my_printf("%d ", f_stat.st_nlink);
    my_printf("%s %s ", f_passwd->pw_name, f_group->gr_name);
    my_printf("%d ", f_stat.st_size);
    my_printf("%s ", store->time);
    my_printf("%s\n", str);
}

void print_with_spe(my_struct *store, char *str)
{
    if (str[0] == '.' && store->specifier->d == 0)
        return;
    if (str[0] == '.' && str[1] != '\0')
        return;
    if (store->specifier->d >= 1 && store->specifier->l == 0
        && store->specifier->lock_d == 0) {
        my_printf(".\n");
        store->specifier->lock_d = 1;
    }
    if (store->specifier->l >= 1 && store->specifier->total_l == 0) {
        store->specifier->total_l = 1;
        my_printf("total 0\n");
    }
    if (store->specifier->l >= 1)
        print_with_l(store, str);
    if (store->specifier->d == 0 && store->specifier->l == 0
        && store->specifier->R == 0 && store->specifier->r == 0
        && store->specifier->t == 0)
        my_printf("%s\n", str);
}

void specifier(char *str, my_struct *store)
{
    for (int nb = 1; str[nb] != '\0'; nb += 1) {
        if (str[nb] != 'l' && str[nb] != 'R' && str[nb] != 'd'
            && str[nb] != 'r' && str[nb] != 't')
            error_management(store);
        if (str[nb] == 'l')
            store->specifier->l += 1;
        if (str[nb] == 'R')
            store->specifier->R += 1;
        if (str[nb] == 'd')
            store->specifier->d += 1;
        if (str[nb] == 'r')
            store->specifier->r += 1;
        if (str[nb] == 't')
            store->specifier->t += 1;
    }
}

void my_ls(int argc, char **argv, my_struct *store)
{
    DIR *link;
    struct dirent *dir;

    for (int nb = 1; nb < argc; nb += 1) {
        if (argv[nb][0] == '-')
            specifier(argv[nb], store);
        else
            store->link = argv[nb];
    }
    if (verif_dir(store) == 1)
        return;
    link = opendir(store->link);
    if (link == NULL)
        error_management(store);
    verif_link(store);
    while ((dir = readdir(link)) != NULL) {
        print_with_spe(store, dir->d_name);
    }
    closedir(link);
}

int main(int argc, char **argv)
{
    my_struct *store;

    store = malloc(sizeof(my_struct));
    store->specifier = malloc(sizeof(spe));
    init_struct(store);
    my_ls(argc, argv, store);
    destroy_struct(store);
    return (0);
}