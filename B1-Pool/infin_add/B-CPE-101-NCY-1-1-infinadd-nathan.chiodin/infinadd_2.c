/*
** EPITECH PROJECT, 2020
** infinadd_1
** File description:
** file 2
*/

char *my_strncpyspe(char *dest, char *src, int n)
{
    int count;
    int subcount = 0;

    for (count = 0; src[count] != '\0' ; count += 1)
        if (count >= n) {
            dest[subcount] = src[count];
            subcount += 1;
        }
    dest[subcount] = '\0';
    return (dest);
}