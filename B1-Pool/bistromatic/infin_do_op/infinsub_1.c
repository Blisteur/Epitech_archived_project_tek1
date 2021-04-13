/*
** EPITECH PROJECT, 2020
** infinsub_1
** File description:
** file 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/infin_do_op.h"

int compare_str(char *str1, char *str2)
{
    int count1 = 0;
    int count2 = 0;

    for (count1 = 0; str1[count1] == '0'; count1 += 1);
    for (count2 = 0; str2[count2] == '0'; count2 += 1);
    if (my_strlen(str1) - count1 > my_strlen(str2) - count2)
        return (1);
    if (my_strlen(str2) - count2 > my_strlen(str1) - count1)
        return (2);
    if (str1[count1] > str2[count2])
        return (1);
    if (str2[count2] > str1[count1])
        return (2);
    if (str1[count1] == str2[count2] && str1[count1 + 1] == '\0')
        return (1);
    return (compare_str(str1 + 1, str2 + 1));
}

void calculate_carry_sub(char *result, int len)
{
    for (int count = (len - 1); count > 0; count -= 1) {
        if (result[count] < 0) {
            result[count] = result[count] + 10;
            result[count - 1] = result[count - 1] - 1;
        }
        result[count] += '0';
    }
}

char *print_res_sub(char *result, int len, int sign_exp1, int sign_exp2)
{
    int count = 0;

    calculate_carry_sub(result, len);
    for (; result[count] == '0' && result[count + 1] != '\0'; count += 1);
    if (sign_exp1 == sign_exp2 && sign_exp1 != 1 && result[count] != '0') {
        result[count - 1] = '-';
        count -= 1;
    }
    result = my_strncpyspe(result, result, count);
    return (result);
}

char *surgery_sub(char **exptab, char *result, int x, int y)
{
    int strc1 = (my_strlen(exptab[x]) - 1);
    int strc2 = (my_strlen(exptab[y]) - 1);
    int lock = 0;

    for (int count = my_strlen(result) - 1; count > 0; count -= 1) {
        if (strc1 < 0) {
            exptab[x][0] = '0';
            strc1 = 0;
            lock = 1;
        } else if (strc2 < 0) {
            exptab[y][0] = '0';
            strc2 = 0;
            lock = 2;
        }
        result[count] = (exptab[x][strc1] - '0') - (exptab[y][strc2] - '0');
        strc1 = (lock == 0 || lock == 2) ? strc1 - 1 : strc1;
        strc2 = (lock == 0 || lock == 1) ? strc2 - 1 : strc2;
    }
    return (result);
}

char *infinsub(char **exptab, int sign_exp1, int sign_exp2)
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
    if (compare_str(exptab[1], exptab[2]) == 1)
        result = surgery_sub(exptab, result, 1, 2);
    if (compare_str(exptab[1], exptab[2]) == 2) {
        result = surgery_sub(exptab, result, 2, 1);
        sign_exp1 = -1;
        sign_exp2 = -1;
    }
    return (print_res_sub(result, (len_res + 1), sign_exp1, sign_exp2));
}