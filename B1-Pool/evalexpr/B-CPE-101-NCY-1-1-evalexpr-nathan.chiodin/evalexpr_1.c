/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/eval_expr.h"

int calculate(int exp1, int exp2, char op);

int count_nb(char *str, int res);

char *make_npi(char *str, char *npi, char *npiop)
{
    int count = 0;
    int countnpi = 0;
    int countnpiop = 0;

    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9') {
            npi[countnpi] = str[count];
            countnpi += 1;
        }
        if (str[count] == '+' || str[count] == '-' || str[count] == '*'
        || str[count] == '/' || str[count] == '%') {
            npiop[countnpiop] = str[count];
            countnpiop += 1;
        }
        count += 1;

    }
    npi[countnpi] = '\0';
    npiop[countnpiop] = '\0';
    npi = my_strcat(npi, my_strdup(npiop));
    return (npi);

}

/*int nb_to_str(char *str, char *npi, int subcount)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9') {
            npi[subcount] = str[count];
            subcount += 1;
        }
        if (str[count] < '0' || str[count] > '9') {
                if (str[count + 1] != '\0') {
                npi[subcount] = '_';
                subcount += 1;
            }
        }
        count += 1;
    }
    return (subcount);
}

void sgn_to_str(char *str, char *npi, int subcount)
{
    int count = my_strlen(str);

    while (count >= 0) {
        if (str[count] == '+' || str[count] == '-'
        || str[count] == '*' || str[count] == '/' || str[count] == '%') {
            npi[subcount] = str[count];
            subcount += 1;
        }
        count -= 1;
    }
    return;
}

int print_res(char *str, int nb)
{
    int exp1 = 0;
    int exp2 = 0;
    char op = 'x';

    str = str + nb;
    op = *str;
    exp2 = my_strtolrev(str, &str);
    while (my_strlen(str) != 0) {
        exp1 = my_strtolrev(str, &str);
        exp2 = calculate(exp1, exp2, op);
    }
    return (exp2);
}*/

int eval_expr(char const *str)
{
    char *npi = malloc(sizeof(char) * (my_strlen(str) * 2));
    char *npiop = malloc(sizeof(char) * (my_strlen(str) * 2));
    int nb = 0;

    printf("test 1\n");
    //nb = nb_to_str(p, npi, nb);
    //sgn_to_str(p, npi, nb);
    npi = make_npi(str, npi, npiop);
    printf("%s string npi\n", npi);
    //print_res(npi, nb);
    free (npi);
    free (npiop);
}
