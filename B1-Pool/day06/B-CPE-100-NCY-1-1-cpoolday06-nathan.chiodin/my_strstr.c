/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** task05
*/
#include <stdio.h>

int my_strlen(char const *str)
{
    int count;

    for (count = 0; str[count] != '\0'; count ++);
    return (count);
}

char *my_strstr(char *str, char const *to_find)
{
    int count1 = my_strlen(to_find);
    int count2 = my_strlen(str);
    int temp = 0;
    int lock = 0;
    int oc;

    for (int test = 0; test < count2; test ++) {
        if (str[test] == to_find[temp]) {
            temp ++;
            oc = test - count1 + 1;
            lock ++;
        } else {
            temp = 0;
            test = test - lock;
            lock = 0;
        }
        if (temp == count1)
            return (str + oc);
    }
    return (NULL);
}
