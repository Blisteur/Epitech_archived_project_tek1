/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** task09
*/

char *my_strlowcase(char *str)
{
    for (int count = 0; str[count] != '\0'; count ++) {
        if (str[count] <= 'Z' && str[count] >= 'A')
            str[count] = str[count] + 32;
    }
    return (str);
}
