/*
** EPITECH PROJECT, 2020
** infindiv_1
** File description:
** file 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

void calculate_carry_div(char *result, int len)
{
    for (int count = 0; count < (len - 1); count += 1) {
        if (result[count] > 9) {
            result[count - 1] = result[count - 1] + result[count] / 10;
            result[count] = result[count] % 10;
        }
        result[count] += '0';
    }
}

char *print_res_div(char *result, int len, int sign_exp1, int sign_exp2)
{
    int count = 0;

    calculate_carry_div(result, len);
    for (; result[count] == '0' && result[count + 1] != '\0'; count += 1);
    if (sign_exp1 != sign_exp2 && result[count] != '0') {
        result[count - 1] = '-';
        count -= 1;
    }
    result = my_strncpyspe(result, result, count);
    return (result);
}

char *surgery_div(char **exptab, char *result, int div)
{
    int strc1 = 0;
    int nb = 0;

    for (int count = 0; result[count] != '\0'; count += 1, strc1 += 1) {
        if (result[count] == '0')
            result[count] = result[count] - '0';
        if (nb <= 0)
            nb = (exptab[1][strc1] - '0');
        else if (nb > 0)
            nb = (nb * 10) + (exptab[1][strc1] - '0');
        if ((nb / div) < 0)
            result[count] = 0;
        if ((nb / div) > 0) {
            result[count] = (nb / div);
            nb -= div * (nb / div);
        }
    }
    return (result);
}

char *infindiv(char **exptab, int sign_exp1, int sign_exp2)
{
    char *result;
    int len_res = my_strlen(exptab[1]);
    int div = my_atoi(exptab[2]);

    if (div <= 0)
        return ("NULL");
    result = malloc(sizeof(char) * (len_res + 1));
    result = initialise_result(result, len_res + 1);
    result = surgery_div(exptab, result, div);
    return (print_res_div(result, (len_res + 1), sign_exp1, sign_exp2));
}