/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** task04
*/
#include "include/my.h"

int is_alphanumeric(char c)
{
    if (c >= '0' && c <= '9' ||
        c >= 'A' && c <= 'Z' ||
        c >= 'a' && c <= 'z') {
        return (1);
    }
    return (0);
}

int how_many_word(char const *str)
{
    int lock = 0;
    int word = 0;

    for (int count = 0; str[count] != '\0'; count++) {
        if (is_alphanumeric(str[count]) == 1)
            lock = 1;
        else if (lock == 1) {
            lock = 0;
            word++;
        }
    }
    return (word);
}

char **my_str_to_word_array(char const *str)
{
    int lock = 0;
    int x = 0;
    int y = 0;
    char **list;

    list = malloc(sizeof(char *) * (how_many_word(str) + 1));
    for (int count = 0; count <= how_many_word(str); count++)
        list[count] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int count = 0; str[count] != '\0'; count++) {
        if (is_alphanumeric(str[count]) == 1) {
            list[x][y] = str[count];
            y++;
            lock = 1;
        } else if (lock == 1) {
            list[x][y] = '\0';
            lock = 0;
            y = 0;
            x++;
        }
    }
    
    list[x + 1] = 0;
    return (list);
}

void main()
{
    my_str_to_word_array("je suis un");
}
