/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** task14
*/

int my_str_islower(char const *str)
{
    for (int count = 0; str[count] != '\0'; count ++) {
        if (str[count] > 'z' || str[count] < 'a')
            return (0);
    }
    return (1);
}
