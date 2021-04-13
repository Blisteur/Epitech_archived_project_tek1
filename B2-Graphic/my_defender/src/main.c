/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "my_defender.h"

void help_msg(void)
{
    int fd = open("src/files/help.txt", O_RDONLY);
    char buff[464];

    buff[463] = '\0';
    if (fd == -1)
        return;
    if (read(fd, buff, 463) == -1) {
        close(fd);
        return;
    }
    my_printf("%s\n", buff);
    close(fd);
}

int main(const int argc, const char * const *argv)
{
    if (argc > 1 || (argc == 2 && my_strcmp(argv[1], "-h") == 0)) {
        help_msg();
        return (0);
    }
    game();
    return (0);
}