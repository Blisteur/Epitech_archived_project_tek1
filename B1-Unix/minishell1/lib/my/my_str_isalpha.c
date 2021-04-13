/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** task12
*/

int my_str_isalpha(char const *str)
{
    for (int nb = 0; str[nb]; nb += 1) {
        if (str[nb] < '0' || str[nb] > '9'
            && str[nb] < 'A' || str[nb] > 'Z'
            && str[nb] < 'a' || str[nb] > 'z')
            return (1);
    }
    return (0);
}