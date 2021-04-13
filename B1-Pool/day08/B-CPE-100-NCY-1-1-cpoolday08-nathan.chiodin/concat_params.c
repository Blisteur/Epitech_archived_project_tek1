/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** task02
*/
#include <stdlib.h>

char *my_strcatspe(char *dest, char const *src, int subcount, int argc)
{
    int len;
    int count;

    for (len; dest[len] != '\0'; len++);
    for (count = 0; src[count] != '\0'; count++)
        dest[len + count] = src[count];
    if (subcount != (argc - 1))
        dest[len + count] = '\n';
    else;
    return (dest);
}

char *concat_params(int argc, char **argv)
{
    char *dest;
    int how_many_space = 0; 
    int count;

    for (count = 0; count != argc; count++)
        how_many_space = how_many_space + my_strlen(argv[count]);
    dest = malloc(sizeof(char) * how_many_space + 1);
    my_strcpy(dest, "\0");
    for (int subcount = 0; subcount != argc; subcount++)
        my_strcatspe(dest, argv[subcount], subcount, argc);
    return (dest);
}
