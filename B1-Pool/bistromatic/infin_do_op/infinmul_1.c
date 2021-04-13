/*
** EPITECH PROJECT, 2020
** infinmul_1
** File description:
** file 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

void calculate_carry_mul(char *result, int len)
{
    for (int count = (len - 1); count > 0; count -= 1) {
        if (result[count] > 9) {
            result[count - 1] = result[count - 1] + result[count] / 10;
            result[count] = result[count] % 10;
        }
        result[count] += '0';
    }
}

char *print_res_mul(char *result, int len, int sign_exp1, int sign_exp2)
{
    int count = 0;

    calculate_carry_mul(result, len);
    for (; result[count] == '0' && result[count + 1] != '\0'; count += 1);
    if (sign_exp1 != sign_exp2 && result[count] != '0') {
        result[count - 1] = '-';
        count -= 1;
    }
    result = my_strncpyspe(result, result, count);
    return (result);
}

char *surgery_mul(char **exptab, char *result, int x, int y)
{
    int strc1 = (my_strlen(exptab[x]) - 1);
    int strc2 = (my_strlen(exptab[y]) - 1);
    int nb = strc1;
    int subcount = my_strlen(result) - 1;

    for (int count = my_strlen(result) - 1; count > 0; count -= 1) {
        if (strc1 < 0) {
            strc1 = nb;
            subcount -= 1;
            count = subcount;
            strc2 -= 1;
        }
        if (strc2 < 0)
            break;
        if (result[count] == '0')
            result[count] = result[count] - '0';
        result[count] += ((exptab[x][strc1] - '0') * (exptab[y][strc2] - '0'));
        strc1 -= 1;
    }
    return (result);
}

char *infinmul(char **exptab, int sign_exp1, int sign_exp2)
{
    char *result;
    int len_nb1 = my_strlen(exptab[1]);
    int len_nb2 = my_strlen(exptab[2]);

    result = malloc(sizeof(char) * ((len_nb1 + len_nb2) + 1));
    result = initialise_result(result, ((len_nb1 + len_nb2) + 1));
    if (len_nb1 > len_nb2)
        result = surgery_mul(exptab, result, 1, 2);
    else
        result = surgery_mul(exptab, result, 2, 1);
    return (print_res_mul(result, (len_nb1 + len_nb2), sign_exp1, sign_exp2));
}