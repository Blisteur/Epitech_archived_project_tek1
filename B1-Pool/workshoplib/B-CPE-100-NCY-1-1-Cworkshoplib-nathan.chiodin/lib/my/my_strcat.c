/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** task02
*/

char *my_strcat(char *dest, char const *src)
{
    int len;
    int count;

    for (len; dest[len] != '\0'; len++);
    for (count = 0; src[count] != '\0'; count++)
        dest[len + count] = src[count];
    dest[len + count] = '\0';
    return (dest);
}
