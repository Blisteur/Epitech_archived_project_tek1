/*
** EPITECH PROJECT, 2020
** infinadd_1
** File description:
** file 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void print_res(char *result, int len)
{
    int scount = 0;

    for (int count = (len - 1); count > 0; count -= 1) {
        if (result[count] > 9) {
            result[count] = result[count] % 10;
            result[count - 1] = result[count - 1] + 1;
        }
        result[count] += 48;
    }
    for (; result[scount] == '0' && result[scount + 1] != '\0'; scount += 1);
    result = my_strncpyspe(result, result, scount);
    my_putstr(result);
    my_putchar('\n');
}

char *surgery(char **argv, char *result, int strc1, int strc2)
{
    int lock = 0;

    for (int count = my_strlen(result) - 1; count > 0; count -= 1) {
        if (strc1 < 0) {
            argv[1][0] = '0';
            strc1 = 0;
            lock = 1;
        } else if (strc2 < 0) {
            argv[2][0] = '0';
            strc2 = 0;
            lock = 2;
        }
            result[count] = (argv[1][strc1] - '0') + (argv[2][strc2] - '0');
        if (lock == 0 || lock == 2)
            strc1 -= 1;
        if (lock == 0 || lock == 1)
            strc2 -= 1;
    }
    return (result);
}

char *initialise_result(char *result, int len_nb)
{
    for (int count = 0; count != len_nb - 1; count += 1)
        result[count] = '0';
    result[len_nb] = '\0';
    return (result);
}

void nb_len(char **argv)
{
    int len_nb1 = my_strlen(argv[1]);
    int len_nb2 = my_strlen(argv[2]);
    int len = 0;
    char *result;

    if (len_nb1 >= len_nb2) {
        result = malloc(sizeof(char) * (len_nb1 + 2));
        result = initialise_result(result, len_nb1 + 2);
        len = my_strlen(result);
        result = surgery(argv, result, (len_nb1 - 1), (len_nb2 - 1));
    } else if (len_nb2 > len_nb1) {
        result = malloc(sizeof(char) * (len_nb2 + 2));
        result = initialise_result(result, len_nb2 + 2);
        len = my_strlen(result);
        result = surgery(argv, result, (len_nb1 - 1), (len_nb2 - 1));
    }
    print_res(result, len);
    free(result);
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return (84);
    nb_len(argv);
    return (0);
}