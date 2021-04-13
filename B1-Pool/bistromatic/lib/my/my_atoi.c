/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** desc
*/

int my_atoi(char *str)
{
    int res = 0;
    int count = 0;

    while (str[count] >= '0' && str[count] <= '9') {
        res = (res * 10) + (str[count] - '0');
        count++;
    }
    return (res);
}
