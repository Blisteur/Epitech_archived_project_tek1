/*
** EPITECH PROJECT, 2020
** match
** File description:
** match.c
*/

int match(char const *s1, char const *s2)
{
    int c2 = 0;

    for (int c1 = 0; s1[c1] != '\0' || s2[c2] != '\0'; c1++, c2++) {
        while (s2[c2] == '*')
            c2++;
        while (s1[c1] != s2[c2]) {
            if (s1[c1] == '\0')
                return (0);
            c1++;
        }
    }
    return (1);
}