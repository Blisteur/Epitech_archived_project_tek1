/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/102architect.h"
#include "include/struct.h"

int invalid_argument(void)
{
    fprintf(stderr, "ERROR : invalide argument\nUSE ./102architect -h for help\n");
    exit(84);
}

void arg_number(char *str)
{
    int nb = 0;
    int lock = 0;

    if (str[0] == '-') {
        nb = 1;
        if (strlen(str) == 1)
            invalid_argument();
    }
    for (; str[nb] != '\0'; nb += 1) {
        if ((str[nb] > '9' || str[nb] < '0') && str[nb] != '.')
            invalid_argument();
        if (str[nb] == '.') {
            lock += 1;
            if (lock > 1)
                invalid_argument();
        }
    }
}

void verif_flags(int argc, char **argv)
{
    for (int nb = 3; nb < argc; nb += 1) {
        if (argv[nb][0] == '-' && argv[nb][1] == 't' && argv[nb][2] == '\0') {
            if (nb + 2 >= argc)
                invalid_argument();
            arg_number(argv[nb + 1]);
            arg_number(argv[nb + 2]);
            nb += 2;
        } else if (argv[nb][0] == '-' && argv[nb][1] == 'z' && argv[nb][2] == '\0') {
            if (nb + 2 >= argc)
                invalid_argument();
            arg_number(argv[nb + 1]);
            arg_number(argv[nb + 2]);
            nb += 2;
        } else if (argv[nb][0] == '-' && argv[nb][1] == 'r' && argv[nb][2] == '\0') {
            if (nb + 1 >= argc)
                invalid_argument();
            arg_number(argv[nb + 1]);
            nb += 1;
        } else if (argv[nb][0] == '-' && argv[nb][1] == 's' && argv[nb][2] == '\0') {
            if (nb + 1 >= argc)
                invalid_argument();
            arg_number(argv[nb + 1]);
            nb += 1;
        } else
            invalid_argument();
    }
}

void error_management(int argc, char **argv)
{
    if (argc < 5)
        invalid_argument();
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        help();
    arg_number(argv[1]);
    arg_number(argv[2]);
    if (argc > 3) {
            verif_flags(argc, argv);
    }
}