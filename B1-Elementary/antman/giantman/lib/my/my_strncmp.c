/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int column = 0; column < n; column++) {
        for (int count = 0; count < 127; count++) {
            if (s1[column] > s2[column])
                return (1);
            if (s1[column] < s2[column])
                return (-1);
        }
    }
    return (0);
}