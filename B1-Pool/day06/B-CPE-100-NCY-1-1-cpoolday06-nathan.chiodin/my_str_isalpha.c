/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** task12
*/

int my_str_isalpha(char const *str)
{
    for (int count = 0; str[count] != '\0'; count ++) {
        if (str[count] > 'z' || (str[count] < 'A' || str[count] > 'Z' && str[count] < 'a'))
            return (0);
    }
    return (1);    
}
