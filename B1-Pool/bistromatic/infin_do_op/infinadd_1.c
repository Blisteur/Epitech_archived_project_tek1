/*
** EPITECH PROJECT, 2020
** infinadd_1
** File description:
** file 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

void calculate_carry_add(char *result, int len)
{
    for (int count = (len - 1); count > 0; count -= 1) {
        if (result[count] > 9) {
            result[count] = result[count] % 10;
            result[count - 1] = result[count - 1] + 1;
        }
        result[count] += '0';
    }
}

char *print_res_add(char *result, int len, int sign_exp1, int sign_exp2)
{
    int count = 0;

    calculate_carry_add(result, len);
    for (; result[count] == '0' && result[count + 1] != '\0'; count += 1);
    if (sign_exp1 == sign_exp2 && sign_exp1 != 1 && result[count] != '0') {
        result[count - 1] = '-';
        count -= 1;
    }
    result = my_strncpyspe(result, result, count);
    return (result);
}

char *surgery_add(char **exptab, char *result)
{
    int strc1 = (my_strlen(exptab[1]) - 1);
    int strc2 = (my_strlen(exptab[2]) - 1);
    int lock = 0;

    for (int count = my_strlen(result) - 1; count > 0; count -= 1) {
        if (strc1 < 0) {
            exptab[1][0] = '0';
            strc1 = 0;
            lock = 1;
        } else if (strc2 < 0) {
            exptab[2][0] = '0';
            strc2 = 0;
            lock = 2;
        }
        result[count] = (exptab[1][strc1] - '0') + (exptab[2][strc2] - '0');
        strc1 = (lock == 0 || lock == 2) ? strc1 - 1 : strc1;
        strc2 = (lock == 0 || lock == 1) ? strc2 - 1 : strc2;
    }
    return (result);
}

char *infinadd(char **exptab, int sign_exp1, int sign_exp2)
{
    char *result;
    int len_nb1 = my_strlen(exptab[1]);
    int len_nb2 = my_strlen(exptab[2]);
    int len_res = 0;

    if (len_nb1 >= len_nb2)
        len_res = len_nb1;
    if (len_nb2 > len_nb1)
        len_res = len_nb2;
    result = malloc(sizeof(char) * (len_res + 2));
    result = initialise_result(result, len_res + 2);
    result = surgery_add(exptab, result);
    return (print_res_add(result, (len_res + 1), sign_exp1, sign_exp2));
}